#include <iostream>

using namespace std;


// 从内往外 *f1(int) 表示f1是一个函数指针，返回值也是一个指针
int (*f1(int))(int*, int);

int* f1(int*, int);

int main(){
    void* p = 0;
    char *c = (char *)malloc(sizeof(char));
    cout << sizeof(p) << endl;
    cout << sizeof(c) << endl;
    return 0;
}