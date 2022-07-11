#include <iostream>
using namespace std;


// 字节对齐规则
class Entity
{
    char c1;
    int val;
};

class Entity1
{
    char cval;
    short ival;
    double dval;
};

class Entity2
{
    char cval;
    double dval;
    char cval2;
    int ival;
};

// 带有虚函数
class Entity3
{
    char cval;
    virtual void vfunc() {}
};

// 单一的类 布袋虚函数
class A
{
private:
    short val1;

public:
    int val2;
    double d;
    static char ch;
    void funcA1() {}
};

// 带有虚函数
class B
{
private:
    short val1;

public:
    int val2;
    double d;
    static char ch;
    void funcA1() {}
    virtual void vfuncA1() {}
    virtual void vfuncA2() {}
};


// 单一继承 不带虚函数
class AA
{
public:
    char aval;
    static int sival;
    void funcA1();
};
class BB : public AA
{
public:
    double bval;
    void funcB1();
};
class CC : public BB
{
public:
    int cval;
    void funcC1() {}
};

// 单一继承，带有虚函数
class AAA
{
public:
    char aval;
    static int sival;
    virtual void vfuncA1() {}
    virtual void vfuncA2() {}
};
class BBB : public AAA
{
public:
    double bval;
    virtual void vfuncA1() {}
    virtual void vfuncB() {}
};
class CCC : public BBB
{
public:
    int cval;
    virtual void vfuncA1() {}
    virtual void vfuncC() {}
};

// 多继承
class AAAA
{
    char aval;
    virtual void vfuncA1() {}
    virtual void vfuncA2() {}
};
class BBBB
{
    double bval;
    virtual void vfuncB1() {}
    virtual void vfuncB2() {}
};
class CCCC : public AAAA, public BBBB
{
    char cval;
    virtual void vfuncC() {}
    virtual void vfuncA1() {}
    virtual void vfuncB1() {}
};

// 菱形继承


int main()
{
    Entity entity;
    cout << "the size of entity is " << sizeof(entity) << endl;
    Entity1 entity1;
    cout << "the size of entity1 is " << sizeof(entity1) << endl;
    Entity2 entity2;
    cout << "the size of entity2 is " << sizeof(entity2) << endl;

    Entity3 entity3;
    cout << "the size of entity3 is " << sizeof(entity3) << endl;

    A a;
    cout << "the size of A is " << sizeof(a) << endl;

    B b;
    cout << "the size of B is " << sizeof(b) << endl;


    // 单一继承，不带虚函数
    AA aa;
    BB bb;
    CC cc;
    cout << "the size of AA is " << sizeof(aa) << endl;
    cout << "the size of BB is " << sizeof(bb) << endl;
    cout << "the size of CC is " << sizeof(cc) << endl;

    // 单一继承，带虚函数
    AAA aaa;
    BBB bbb;
    CCC ccc;
    cout << "the size of AAA is " << sizeof(aaa) << endl;
    cout << "the size of BBB is " << sizeof(bbb) << endl;
    cout << "the size of CCC is " << sizeof(ccc) << endl;

    // 多重继承
    AAAA aaaa;
    BBBB bbbb;
    CCCC cccc;
    cout << "the size of AAAA is " << sizeof(aaaa) << endl;
    cout << "the size of BBBB is " << sizeof(bbbb) << endl;
    cout << "the size of CCCC is " << sizeof(cccc) << endl;

    return 0;
}
