#include <iostream>

using namespace std;

// 单继承时的虚函数表
// 1、无虚函数覆盖
class Base
{
public:
	virtual void x() { cout << "Base::x()" << endl; }
	virtual void y() { cout << "Base::y()" << endl; }
	virtual void z() { cout << "Base::z()" << endl; }
};

class Derive : public Base
{
public:
	void x1(){
		cout << "Derive::x1()" << endl;
	}
	// virtual void x1() { cout << "Derive::x1()" << endl; }
	// virtual void y1() { cout << "Derive::y1()" << endl; }
	// virtual void z1() { cout << "Derive::z1()" << endl; }
};

int main(){
    Base b;
    Derive d;

    return 0;
}