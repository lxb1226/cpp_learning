#include <iostream>
#include <memory>

using namespace std;

// int a = 1;

class A;
class B;

class B
{
public:
    shared_ptr<A> a;
    B() = default;

    void print()
    {
        cout << "B " << endl;
    }
};

class A
{
public:
    weak_ptr<B> b;
    A() = default;

    void print()
    {
        cout << "A " << endl;
    }
};

int main()
{
    // cout << "a : " << a << endl;
    A a;

    B b;
    b.a->print();
    return 0;
}