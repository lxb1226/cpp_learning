#include <iostream>
using namespace std;

template<typename T> void TempFun(T a){
    cout << a << endl;
}

void DefParm(int m = 3){}

template<typename T = int>
    class DefClass{};
template<typename T = int>
    void DefTempParm() {};

template<typename T1, typename T2 = int> class DefClass1;
template<typename T1 = int, typename T2> class DefClass1;   // 无法通过编译

template<typename T, int i = 0> class DefClass3;
//template<int i = 0, typename T> class DefClass4;    // 无法通过编译

template<typename T1 = int, typename T2> void DefFunc1(T1 a, T2 b);
template<int i = 0, typename T> void DefFunc2(T a);


int main(){
    TempFun(1);
    TempFun("1");
}