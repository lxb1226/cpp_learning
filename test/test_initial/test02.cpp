#include <iostream>

using namespace std;

class Person{
    public:
        Person(){
            cout << "Person" << endl;
        }
        ~Person(){
            cout << "~Person" << endl;

        }
};

int main(){
    Person* p = new Person[5];

    delete[] p;
    return 0;
}