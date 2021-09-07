#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<bool> ready(false);             // can be checked without being set
std::atomic_flag winner = ATOMIC_FLAG_INIT; // always set when checked

void count1m(int id)
{
    while (!ready)
    {
        std::this_thread::yield();
    } // 等待主线程中设置 ready 为 true.

    for (int i = 0; i < 1000000; ++i)
    {

    } // 计数

    // 如果某个线程率先执行完上面的计数过程，则输出自己的 ID.
    // 此后其他线程执行 test_and_set 是 if 语句判断为 false，
    // 因此不会输出自身 ID.
    if (!winner.test_and_set())
    {
        std::cout << "thread #" << id << " won!\n";
    }
};

int main()
{

    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 millions...\n";
    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(count1m, i));
    ready = true;

    for (auto &th : threads)
        th.join();

    return 0;
}