#include <cassert>

using namespace std;

enum FeatureSupports{
    C99 = 0x0001,
    ExtInt = 0x0002,
    SAssert = 0x0004,
    NoExcept = 0x0008,
    SMAX =  0x0010
};

// 一个编译器类型，包括名称、特性支持等
struct Compiler{
    const char* name;
    int spp;    // 使用FeatureSupports枚举
};

int main(){
    // 检查枚举值是否完备
    assert((SMAX - 1) == (C99 | ExtInt | SAssert | NoExcept));

    Compiler a = {"abc", (C99 | SAssert)};

    if(a.spp & C99){

    }
}