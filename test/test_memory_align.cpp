#include <iostream>
using namespace std;

class MyStruct
{
    char dda;    //偏移量为0，满足对齐方式，dda占用1个字节；
    double dda1; //下一个可用的地址的偏移量为1，不是sizeof(double)=8的倍数，需要补足7个字节才能使偏移量变为8（满足对齐方式），因此VC自动填充7个字节，dda1存放在偏移量为8的地址上，它占用8个字节。
    int type;    //下一个可用的地址的偏移量为16，是sizeof(int)=4的倍数，满足int的对齐方式，所以不需要VC自动填充，type存放在偏移量为16的地址上，它占用4个字节。
    //共占20个字节，不是默认偏移量（8）的整数倍，需要进行字节填充，最终占24个字节
};

class MyStruct1
{
    double d1; //偏移量0，满足对齐方式，d1占用8个字节
    char d2;   //偏移量为8，满足对其方式（是1的倍数），占用1个字节
    int d3;    //偏移量为9，不满足对其方式（不是4的倍数），需要补3个字节，9+3+4=16
    //最终，占16个字节，是默认偏移量（8）的整数倍，不用补充字节
};

int main()
{
    cout << sizeof(MyStruct) << endl;
    cout << sizeof(MyStruct1) << endl;
    return 0;
}