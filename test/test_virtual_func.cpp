#include <iostream>

using namespace std;

class Base{
    public:
        Base() = default;

        virtual ~Base() = default;

        virtual void A(){
            cout << "Base::A()" << endl;
        }

        virtual void B(){
            cout << "Base::B()" << endl;
        }

        void C(){
            cout << "Base::C()" << endl;
        }
};

class Derived: public Base{
    public:
        Derived() = default;
        virtual ~Derived() =default;

        virtual void A(){
            cout << "Derived::A()" << endl;
        }
        void B(){
            Base::A();
            Base::C();
            cout << "Derived::B()" << endl;
        }
};

int main(){
    Derived derived;
    derived.B();

    return 0;
}