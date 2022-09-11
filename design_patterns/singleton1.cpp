#include <thread>
#include <mutex>

// C++11 标准保证其的线程安全
class Singleton{
    public:
        static Singleton* getInstance(){
            static Singleton instance;
            return &instance;
        }

    private:
        Singleton();
        ~Singleton();
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
};