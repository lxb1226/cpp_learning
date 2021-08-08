#include <iostream>
using namespace std;

// 自定义ColorVector，对齐到32字节的边界
struct alignas(32) ColorVector{
    double r;
    double g;
    double b;
    double a;
};

int main(){
    cout << "alignof(ColorVector): " << alignof(ColorVector) << endl;
    return 1;
}