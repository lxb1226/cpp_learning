#include <iostream>
using namespace std;

class A
{
    virtual void func()
    {
        cout << "A's func is called" << endl;
    }
};

class B : public A
{
    virtual void func()
    {
        cout << "B's func is called" << endl;
    }
};

int main()
{
    A a;
    B b;
    cout << "Vtable address of A is " << *(void **)&a << endl;
    cout << "Vtable address of B is " << *(void **)&b << endl;
    A tmp = b;
    cout << "after upcast and copy:  " << *(void **)&tmp << endl;
    A *p = &b;
    cout << "after upcast and reference:  " << *(void **)&(*p) << endl;
}