#include <iostream>
using namespace std;

// 空类， 只有一个字节
class A
{
};

// 带有虚函数的类，需要添加一个指针，指向虚函数表
class B
{
    char ch;
    virtual void func0() {}
};

class C
{
    char ch1;
    char ch2;
    virtual void func() {}
    virtual void func1() {}
};

// 单继承 有虚函数覆盖
class D : public C
{
    int d;
    virtual void func() {}
    virtual void func0() {}
    virtual void func1() {}
};

// 多重继承： 有虚函数覆盖
class E : public B, public C
{
    int e;
    virtual void func0() {}
    virtual void func1() {}
};

// 多重继承：没有虚函数覆盖
class F : public B, public C
{
    int f;
    virtual void funcf() {}
    virtual void funcf1() {}
};

int main(void)
{
    cout << "A=" << sizeof(A) << endl;   // result=1
    cout << "B=" << sizeof(B) << endl;   // result=16
    cout << "C=" << sizeof(C) << endl;   // result=16
    cout << "D=" << sizeof(D) << endl;   // result=16 1 + 1 + 2 + 4 + 8
    cout << "E=" << sizeof(E) << endl;   // result=32
    cout << "F=" << sizeof(F) << endl; // result=32  1 + 1 + 1 + 1 + 4 + 8 * 3
    return 0;
}