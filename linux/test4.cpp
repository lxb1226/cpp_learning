#include <stdio.h>

class A
{
public:
    int a;
};

class C : public virtual A
{
public:
    int c;
};

void func1(C c)
{
    printf("implement it\n");
}

void func2(const C &c)
{
    printf("implement it\n");
}

int main()
{
    C c = C();
    func1(c);
    func2(c);
}
