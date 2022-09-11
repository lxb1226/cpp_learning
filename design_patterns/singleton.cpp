#include <thread>
#include <mutex>


class Singleton{
    public:
        static Singleton* getInstance(){
            // 双检查锁
            // 好处是只有判断指针为空的时候才加锁，避免了每次调用getInstance的方法都加锁。减少锁的开销
            if(instance_ == nullptr){
                std::unique_lock<std::mutex> lock(mtx);
                if(instance_ == nullptr){
                    instance_ = new (std::nothrow) Singleton();
                }
            }
            return instance_;
            
        };

    private:
        Singleton();
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);

        static Singleton* instance_;
        static std::mutex mtx;
};


