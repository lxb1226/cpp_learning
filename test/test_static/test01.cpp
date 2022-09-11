#include<iostream>

using namespace std;

// 测试局部static 变量
int fun1(int a){
    static int b = 5;
    a = a + b;
    b = a;
    return a;
}

int main(){
    int a = 10;
    auto res = fun1(a);
    cout << res << endl;
    res = fun1(a);
    cout << res << endl;

    return 0;
}