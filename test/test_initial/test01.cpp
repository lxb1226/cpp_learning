#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "默认构造函数A()" << endl;
    }
    A(int a)
    {
        value = a;
        cout << "A(int " << value << ")" << endl;
    }
    A(const A &a)
    {
        value = a.value;
        cout << "拷贝构造函数A(A& a):  " << value << endl;
    }
    int value;
};

class B
{
public:
    B() : a(1)
    {
        b = A(2);
    }
    A a;
    A b;
};
int main()
{
    B b;
}

//输出结果：
// A(int 1)
//默认构造函数A()
// A(int 2)
