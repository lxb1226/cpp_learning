#include <iostream>

using namespace std;

// 多重继承时的虚函数表
// 2、有虚函数覆盖
class Base1
{
public:
	virtual void x() { cout << "Base1::x()" << endl; }
	virtual void y() { cout << "Base1::y()" << endl; }
	virtual void z() { cout << "Base1::z()" << endl; }
};

class Base2
{
public:
	virtual void x() { cout << "Base2::x()" << endl; }  
	virtual void y() { cout << "Base2::y()" << endl; }
	virtual void z() { cout << "Base2::z()" << endl; }
};

class Derive : public Base1, public Base2
{
public:
	virtual void x() { cout << "Derive::x()" << endl; }     // 重写
	virtual void y1() { cout << "Derive::y1()" << endl; }
};

int main(){
    Base1 b;
    Base2 b2;
    Derive d;

    return 0;
}