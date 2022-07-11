#include <iostream>
using namespace std;

union A{
    int a[5];
    char b;
    double c;
};

int main(){
    cout << "sizeof(A) : " << sizeof(A) << endl; // sizeof(A) : 24 
    return 0;
}