#include <iostream>

using namespace std;

static int a = 1;

void func1(void){
    a = 2;
}

void func2(void){
    int a = 3;
}

void func3(void){
    static int a = 4;
}

int main(){
    cout << a << endl;
    func1();
    cout << a << endl;
    func2();
    cout << a << endl;
    func3();
    cout << a << endl;
}