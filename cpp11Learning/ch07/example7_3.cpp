#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    // nullptr 可以隐式转换为char*
    char* cp = nullptr;

    // 不可转换为整形，而任何类型也不能转换为nullptr_t
    // int n1 = nullptr;
    // int n2 = reinterpret_cast<int>(nullptr);

    // nullptr 与nullptr_t类型变量可以作比较
    // 当使用==,<=,>=符号比较时返回true
    nullptr_t nptr;
    if(nptr == nullptr){
        cout << "nullptr_t nptr == nullptr" << endl;
    }else{
        cout << "nullptr_t nptr != nullptr" << endl;
    }
    if(nptr < nullptr){
        cout << "nullptr_t nptr < nullptr" << endl;
    }else{
        cout << "nullptr_t nptr !< nullptr" << endl;
    }

    // 不能转换为整形或bool类型
    // if(0 == nullptr);
    // if( nullptr );

    // 不可以进行算术运算，
    // nullptr += 1;
    // nullptr * 5;

    sizeof(nullptr);
    typeid(nullptr);
    throw(nullptr);

    return 0;
}