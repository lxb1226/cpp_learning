#include <iostream>

using namespace std;

void myfun(char a){
    cout << "char" << endl;
}

void myfun(long b){
    cout << "long" << endl;
}

class A{
    public:
        virtual void func(){
            cout << "A func()" << endl;
        };
        ~A(){
            cout << "~A" << endl;
        }
};

class B:public A{
    public:
        void func(){
            A::func();
            cout << "B func()" << endl;
        }
        virtual ~B(){
            cout << "~B" << endl;
        }
};

int main(){

    A* a = new B();
    a->func();
    delete a;

    return 0;
    // char a;
    // char a1[10];
    // char a2[] = "Hello";

    // char *a3;
    // char *a4 = "C++";

    // char a5[] = {'C', '+', '+', '\0'};
    // char *a6 = a5;

    // printf("%s", a5);

    // char str1[] = "abc";
    // char str2[] = "abc";

    // char *str3 = "abc";
    // char *str4 = "abc";

    // cout << (str1 == str2) << endl;
    // cout << (str3 == str4) << endl;

    // int c = 100;
    // myfun(c);

}