#include <thread>
#include <mutex>

class Singleton{
    private:
        static Singleton instance;
    private:
        Singleton();
        ~Singleton();
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);

    public:
        static Singleton& getInstance(){
            return instance;
        }
};

// 初始化
Singleton Singleton::instance;