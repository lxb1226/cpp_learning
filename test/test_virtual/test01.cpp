#include<iostream>

using namespace std;

class Base
{
public:
	virtual void x() { cout << "Base::x()" << endl; }
	virtual void y() { cout << "Base::y()" << endl; }
	virtual void z() { cout << "Base::z()" << endl; }
};

typedef void(*pFun)(void);

int main()
{
	Base b;
	// int* vptr = (int*)&b;                     // 虚函数表地址

	// pFun func1 = (pFun)*((int*)*vptr);        // 第一个函数
	// pFun func2 = (pFun)*((int*)*vptr+1);      // 第二个函数
	// pFun func3 = (pFun)*((int*)*vptr+2);      // 第三个函数
	
	// func1();     // 输出Base::x()
	// func2();     // 输出Base::y()
	// func3();     // 输出Base::z()
	return 0;
}