#include <iostream>
using namespace std;

struct alignas(alignof(double) * 4) ColorVector{
    double r;
    double g;
    double b;
    double a;
};

// 固定容量的模板数组
template<typename T>
class FixedCapacityArray{
public:
    void push_back(T t){}

    char alignas(T) data[1024] = {0};
};

int main(){
    FixedCapacityArray<char> arrCh;
    cout << "alignof(char): " << alignof(char) << endl;
    cout << "alignof(arrCh.data): " << alignof(arrCh.data) << endl;

    // FixedCapacityArray(ColorVector) arrCV;
    
}