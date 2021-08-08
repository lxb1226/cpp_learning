#include <cassert>
using namespace std;

char* ArrayAlloc(int n){
    assert(n > 0);  // 断言，n必须大于0
    return new char[n];
}

int main(){
    char* a = ArrayAlloc(0);
}