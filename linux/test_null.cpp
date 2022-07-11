#include <iostream>

using namespace std;

void f(void*){
    cout << __FUNCTION__ << " : " << __LINE__ << endl;
}

void f(int){
    cout << __FUNCTION__ << " : " << __LINE__ << endl;
}

int main(){
    f(nullptr);
}