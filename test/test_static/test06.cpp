#include <iostream>

using namespace std;

class A{
    public:
        A() = default;
        void print(){
        cout << "A : print()" << endl;
    }
};

static A a;

int main(){
    // cout << "a : " << a << endl;
    a.print();
    return 0;
}