#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <mutex>
#include <queue>
#include <functional>
#include <future>
#include <thread>
#include <utility>
#include <vector>

template <typename T>
class SafeQueue
{
private:
    std::queue<T> m_queue;  // 利用模板函数构造队列

    std::mutex m_mutex;     // 访问互斥信号量

public:
    SafeQueue() {}
    SafeQueue(SafeQueue &&other) {}
    ~SafeQueue() {}

    bool empty()    // 返回队列是否为空
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        return m_queue.empty();
    }

    int size()
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        return m_queue.size();
    }

    // 进队
    void enqueue(T &t)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.emplace(t);
    }

    // 出队
    bool dequeue(T &t)
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        if (m_queue.empty())
            return false;
        t = std::move(m_queue.front());
        m_queue.pop();

        return true;
    }
};


class ThreadPool
{
private:
    class ThreadWorker  // 内置线程工作类
    {
    private:
        int m_id;   // 工作id

        ThreadPool *m_pool; // 所属线程池

    public:
        // 构造函数
        ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool), m_id(id)
        {
        }

        // 重载()操作
        void operator()()
        {
            std::function<void()> func; // 定义基础函数类func

            bool dequeued;  // 是否正在取出队列中元素

            // 判断线程池是否关闭，没有关闭则从任务队列中循环提取任务
            while (!m_pool->m_shutdown)
            {
                {
                    // 为线程环境加锁，访问工作线程的休眠和唤醒
                    std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);

                    // 如果任务调度队列为空，阻塞当前线程
                    if (m_pool->m_queue.empty())
                    {
                        m_pool->m_conditional_lock.wait(lock);  // 等待条件变量通知，开启线程
                    }

                    // 取出任务队列中的元素
                    dequeued = m_pool->m_queue.dequeue(func);
                }

                // 如果成功取出，执行工作函数
                if (dequeued)
                    func();
            }
        }
    };

    bool m_shutdown;

    SafeQueue<std::function<void()>> m_queue;

    std::vector<std::thread> m_threads;

    std::mutex m_conditional_mutex;

    std::condition_variable m_conditional_lock;

public:
    // 线程池构造函数
    ThreadPool(const int n_threads = 4) : m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false)
    {
    }

    ThreadPool(const ThreadPool &) = delete;

    ThreadPool(ThreadPool &&) = delete;

    ThreadPool &operator=(const ThreadPool &) = delete;

    ThreadPool &operator=(ThreadPool &&other) = delete;

    // 初始化线程池
    void init()
    {
        for (int i = 0; i < m_threads.size(); ++i)
        {
            m_threads.at(i) = std::thread(ThreadWorker(this, i));   // 分配工作线程
        }
    }

    // 等待直到线程结束它们当前的任务然后关闭线程池
    void shutdown()
    {
        m_shutdown = true;
        m_conditional_lock.notify_all();

        for (int i = 0; i < m_threads.size(); ++i)
        {
            if (m_threads.at(i).joinable()) // 判断线程是否在等待
            {
                m_threads.at(i).join(); // 将线程加入到等待队列
            }
        }
    }

    // 提交一个将被线程池异步执行的函数
    template <typename F, typename... Args>
    auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))>
    {
        // 创建一个准备好去执行的带有参数的函数
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);

        // 将其封装到共享指针中，以便能够复制构造
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

        // 将打包任务转化为 void function
        std::function<void()> warrper_func = [task_ptr]()
        {
            (*task_ptr)();
        };

        // 队列通用安全封包函数，并压入安全队列
        m_queue.enqueue(warrper_func);

        // 唤醒一个等待中的线程
        m_conditional_lock.notify_one();

        // 返回先前注册的任务指针
        return task_ptr->get_future();
    }
};

#endif