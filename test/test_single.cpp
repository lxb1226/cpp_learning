#include <iostream>
#include <mutex>
#include <memory>

using namespace std;

// std::call_once实现单例
class Singleton3
{
public:
    static std::shared_ptr<Singleton3> getSingleton();

    void print()
    {
        std::cout << "Hello World." << std::endl;
    }

    ~Singleton3()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

private:
    Singleton3()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

static std::shared_ptr<Singleton3> singleton = nullptr;
static std::once_flag singletonFlag;

std::shared_ptr<Singleton3> Singleton3::getSingleton(){
    std::call_once(singletonFlag, [&]{
        singleton = std::shared_ptr<Singleton3>(new Singleton3());
    });

    return singleton;
}

// 饿汉式

class Singleton2
{
public:
    static Singleton2 *GetInstance()
    {
        return g_pSingleton;
    };

    static void deleteInstance()
    {
        if (g_pSingleton)
        {
            delete g_pSingleton;
            g_pSingleton = nullptr;
        }
    };

    void Print();

    Singleton2(const Singleton2 &singleton2) = delete;
    const Singleton2 &operator=(const Singleton2 &singleton2) = delete;

private:
    Singleton2()
    {
        std::cout << "call Singleton2()" << std::endl;
    };
    ~Singleton2()
    {
        std::cout << "call ~Singleton2()" << std::endl;
    };
    static Singleton2 *g_pSingleton;
};

Singleton2 *Singleton2::g_pSingleton = new (std::nothrow) Singleton2();

// 双检查锁 懒汉式单例
class Singleton1
{
public:
    using Ptr = std::shared_ptr<Singleton1>;
    ~Singleton1()
    {
        std::cout << "singleton1 destructor called!" << std::endl;
    }

    Singleton1(const Singleton1 &) = delete;
    Singleton1 &operator=(const Singleton1 &) = delete;

    static Ptr get_instance()
    {
        if (m_instance_ptr == nullptr)
        {
            std::lock_guard<std::mutex> lk(m_mutex);
            if (m_instance_ptr == nullptr)
            {
                m_instance_ptr = std::shared_ptr<Singleton1>(new Singleton1);
            }
        }

        return m_instance_ptr;
    }

private:
    Singleton1()
    {
        std::cout << "Singleton1 constructor called!" << std::endl;
    }
    static Ptr m_instance_ptr;
    static std::mutex m_mutex;
};

Singleton1::Ptr Singleton1::m_instance_ptr = nullptr;
std::mutex Singleton1::m_mutex;

// magic singleton
class Singleton
{
public:
    ~Singleton()
    {
        std::cout << "destructor called!" << std::endl;
    }
    Singleton(const Singleton &) = delete;
    Singleton operator=(const Singleton &) = delete;
    static Singleton &get_instance()
    {
        static Singleton instance;
        return instance;
    }

private:
    Singleton()
    {
        std::cout << "constructor called!" << std::endl;
    }
};

int main()
{
    Singleton &instance1 = Singleton::get_instance();
    Singleton &instance2 = Singleton::get_instance();

    Singleton1::Ptr p1 = Singleton1::get_instance();
    Singleton1::Ptr p2 = Singleton1::get_instance();

    Singleton2 *s21 = Singleton2::GetInstance();
    Singleton2 *s22 = Singleton2::GetInstance();
    Singleton2::deleteInstance();

    

    return 0;
}