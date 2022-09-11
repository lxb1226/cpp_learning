#include <iostream>

using namespace std;

int tmp(){
    static int b = 5;
    return b;
}

int main(){
    int arr[10] = {0};

    cout << arr << endl; // 首元素的地址
    cout << arr + 1 << endl; // 第一个元素的地址

    // cout << arr

    cout << &arr[0] << endl; // 首元素地址
    

    cout << &arr << endl;
    cout << &arr + 1 << endl;

    static int a = 0;
    int c = tmp();
    cout << "a : " << a << endl;
    cout << "c : " << c << endl;

    return 0;
}