#include <iostream>

using namespace std;

class A{
    virtual void func();
};

class B: public virtual A{
    virtual void foo();
};

class C: public A{
    virtual void foo();
};

class D{
    virtual void func();
    char x;
};

class E: public virtual D{
    virtual void foo();
};

class F: public D{
    virtual void foo();
};

int main(){
    A a;
    B b;
    C c;
    D d;
    E e;
    F f;

    cout << "size of A : " << sizeof(a) << endl;
    cout << "size of B : " << sizeof(a) << endl;
    cout << "size of C : " << sizeof(a) << endl;
    cout << "size of D : " << sizeof(a) << endl;
    cout << "size of E : " << sizeof(a) << endl;
    cout << "size of F : " << sizeof(a) << endl;
}

