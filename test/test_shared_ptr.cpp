#include <iostream>
#include <memory>

using namespace std;


// 循环引用
class B;
class A
{
public:
    weak_ptr<B> m_sptrB;

    A() : m_sptrB() {}

    ~A()
    {
        cout << "A is destroyed" << endl;
    }
};

class B
{
public:
    shared_ptr<A> m_sptrA;

    B() : m_sptrA(nullptr) {}

    ~B()
    {
        cout << "B is destroyed" << endl;
    }
};

void test_shared_ptr()
{
    int a = 10;
    std::shared_ptr<int> ptra = std::make_shared<int>(a);
    std::shared_ptr<int> ptra2(ptra); // 拷贝 ptr加1

    std::cout << ptra.use_count() << std::endl;
    std::cout << ptra2.use_count() << std::endl;

    std::cout << "--------------------------" << std::endl;

    int b = 20;
    int *pb = &a;

    std::shared_ptr<int> ptrb = std::make_shared<int>(b);
    ptra2 = ptrb; // 赋值 左边减1 右边加1
    pb = ptrb.get();

    std::cout << ptra.use_count() << std::endl;
    std::cout << ptra2.use_count() << std::endl;
    std::cout << ptrb.use_count() << std::endl;

    std::cout << "------------------------" << std::endl;
    std::shared_ptr<int> tmp(new int(10));
    std::cout << *(tmp.get()) << std::endl;
}

void test_cyccle(){
    shared_ptr<B> sptrB(new B);
    shared_ptr<A> sptrA(new A);

    sptrB->m_sptrA = sptrA;
    sptrA->m_sptrB = sptrB;

    cout << sptrB.use_count() << endl;
    cout << sptrA.use_count() << endl;
}

int main()
{
    test_cyccle();
    return 0;
}