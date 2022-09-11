#include <iostream>
#include <memory>

using namespace std;

class A;
class B;

// 循环引用问题 析构两者都没有调用
class A
{
public:
    shared_ptr<B> bptr;
    ~A()
    {
        cout << "A has been destory!" << endl;
    }
};

class B
{
public:
    weak_ptr<A> aptr;
    // shared_ptr<A> aptr;
    ~B()
    {
        cout << "B has been destory!" << endl;
    }
};

int main()
{
    shared_ptr<A> pa(new A);
    shared_ptr<B> pb(new B);

    cout << "pa count : " << pa.use_count() << endl;
    cout << "pb count : " << pb.use_count() << endl;

    pa->bptr = pb;
    pb->aptr = pa;

    cout << "pa count : " << pa.use_count() << endl;
    cout << "pb count : " << pb.use_count() << endl;
}