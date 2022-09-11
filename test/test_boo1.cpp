#include <iostream>
using namespace std;

int main(){
    unsigned int value = 1024;
    cout << &value << endl;
    bool condition = *(bool*)&value;
    cout << condition << " " << value << endl;
    if(condition){
        value++;
    }
    condition = *(bool*)&value;

    cout << condition << " " << value << endl;
    if(condition){
        value++;
    }
    condition = *(bool*)&value;
    cout << condition << " " << value << endl;
    return 0;
}