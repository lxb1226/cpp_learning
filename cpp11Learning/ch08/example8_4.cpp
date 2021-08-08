#include <iostream>
using namespace std;

class InComplete;
struct Completed{};

int main(){
    int a;
    long long b;
    auto & c = b;
    char d[1024];

    // 对内置类型和完整类型使用alignof
    cout << alignof(int) << endl
        << alignof(Completed) << endl;

    cout << alignof(a) << endl
        << alignof(b) << endl
        << alignof(c) << endl
        << alignof(d) << endl;
    
    // 本句无法通过编译，Incomplete类型不完整
    // cout << alignof(InComplete) << endl;
}