#include <iostream>
#include <memory>

using namespace std;

class Deletor
{
public:
    Deletor() = default;

    template <typename U>
    void operator()(U *p) noexcept
    {
        if (p)
        {
            delete p;
        }
    }
};

template <typename T, typename U = Deletor>
class Myunique_ptr
{
public:
    explicit Myunique_ptr() : ptr(nullptr){}; // 显式构造函数
    explicit Myunique_ptr(T *p) : ptr(p){};
    explicit Myunique_ptr(Myunique_ptr &&p)
    {
        ptr = std::forward<T *>(p.ptr);
        deletor = std::forward<U>(p.deletor);
        p.ptr = nullptr;
    }; // 移动构造函数
    void operator=(Myunique_ptr &&p)
    {
        ptr = std::forward<T *>(p.ptr);
        deletor = std::forward<U>(p.deletor);
        p.ptr = nullptr;
    }; // 移动赋值运算符

    ~Myunique_ptr()
    {
        if (ptr)
        {
            deletor(ptr);
        }

        ptr = nullptr;
    }; // 析构函数

    Myunique_ptr(const Myunique_ptr &p) = delete;           // 不支持拷贝构造函数
    Myunique_ptr operator=(const Myunique_ptr &p) = delete; // 不支持拷贝赋值函数
    Myunique_ptr operator=(T *p) = delete;                  // 不支持裸指针赋值

    T *release()
    {
        T *p = ptr;
        ptr = nullptr;
        return p;
    }; // 释放所有权

    void reset(T *p = nullptr) noexcept
    {
        if (ptr)
        {
            deletor(ptr);
        }

        ptr = p;
    };

    void swap(Myunique_ptr &rhs) noexcept
    {
        std::swap(ptr, rhs.ptr);
        std::swap(deletor, rhs.deletor);
    };

    T *get() noexcept
    {
        return ptr;
    };

    U &get_deletor() noexcept
    {
        return deletor;
    };

    explicit operator bool() const noexcept
    {
        if (ptr)
            return true;
        else
            return false;
    };

    T &operator*() const noexcept
    {
        return *ptr;
    };

    T *operator->() const noexcept
    {
        return ptr;
    };

private:
    T *ptr;    // 值指针
    U deletor; // 删除器
};

class Widget
{
public:
    Widget()
    {
        std::cout << "Widget::constructor" << std::endl;
    }

    ~Widget()
    {
        std::cout << "Widget::destructor" << std::endl;
    }

    void fun()
    {
        std::cout << "Widget::fun" << std::endl;
    }
};

// 支持普通指针
template <class T, class... Args>
inline
    typename enable_if<!is_array<T>::value, unique_ptr<T>>::type
    make_unique(Args &&...args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// 支持动态数组
template <class T>
inline
    typename enable_if<is_array<T>::value && extent<T>::value == 0, unique_ptr<T>>::type
    make_unique(size_t size)
{
    typedef typename remove_extent<T>::type U;
    return unique_ptr<T>(new U[size]());
}

// 过滤掉定长数组的情况
template <class T, class... Args>
typename enable_if<extent<T>::value != 0, void>::type
make_unique(Args &&...) = delete;

void test_unique_ptr()
{
    unique_ptr<int> pInt;

    pInt.reset(new int());
    int *p = pInt.release();

    unique_ptr<int[]> pArray(new int[3]{1, 3, 3});

    cout << "-------------------" << endl;

    unique_ptr<int> uptr(new int(10));
    unique_ptr<int> uptr2 = std::move(uptr);
    cout << *(uptr2.get()) << endl;
    uptr2.release();
}

void test_my_unique_ptr()
{
    Myunique_ptr<int> ptr(new int(1));

    *ptr = 2;
    if (ptr)
    {
        std::cout << "ptr is not null" << std::endl;
    }

    std::cout << *ptr << std::endl;

    ptr.reset();

    if (!ptr)
    {
        std::cout << "ptr is null" << std::endl;
    }

    Myunique_ptr<Widget> w_ptr(new Widget());
    w_ptr->fun();

    Myunique_ptr<Widget> w_ptr2;
    w_ptr2.reset(new Widget());
    w_ptr2->fun();

    auto p = w_ptr.release();

    p->fun();

    delete p;

    std::cout << "=============" << std::endl;

    Myunique_ptr<Widget> w_ptr3(new Widget());
    Myunique_ptr<Widget> w_ptr4;
    w_ptr4.swap(w_ptr3);
    w_ptr4->fun();

    std::cout << "==================" << std::endl;
    w_ptr3 = std::move(w_ptr4);
    w_ptr3->fun();

    std::cout << "#####################" << std::endl;

    Myunique_ptr<Widget> w_ptr5(std::move(w_ptr3));
    w_ptr5->fun();

    std::cout << "###############" << std::endl;
    Myunique_ptr<Widget, Deletor> w_ptr6(new Widget());
}

int main()
{
    test_my_unique_ptr();
    return 0;
}