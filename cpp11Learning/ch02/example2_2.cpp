#include <string>
#include <iostream>
using namespace std;

const char* hello(){ return __func__;}
const char* world(){ return __func__;}

/*
__func__:返回所在函数的名字
*/
int main(){
    cout << hello() << ", " << world() << endl;
}