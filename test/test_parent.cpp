#include <iostream>

using namespace std;

class P
{
public:
    void func()
    {
        cout << "P::func()" << endl;
    }
};

class Derived : public P
{
public:
    void func()
    {
        cout << "D::func()" << endl;
    }
};

int main()
{
    P *p = new Derived();
    p->func();
    ((Derived*)p)->func();

    Derived d;
    d.func();

    P* p1 = reinterpret_cast<P*>(&d);
    p1->func();
}