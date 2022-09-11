#include <iostream>

using namespace std;

int main(){
    void *p = malloc(10);
    cout << sizeof(p) << endl;
}