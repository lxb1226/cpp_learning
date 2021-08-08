#include <memory>
#include <iostream>
using namespace std;

int main(){
    unique_ptr<int> up1(new int(11));
    //unique_ptr<int> up2 = up1;  // 不能通过编译
    cout << *up1 << endl;

    unique_ptr<int> up3 = move(up1);        // 现在p3是数据唯一的unique_ptr智能指针
    cout << *up3 << endl;
    //cout << *up1 << endl;   // 运行时错误
    up3.reset();        // 显式释放内存
    // up1.reset();        // 不会导致运行时错误

    //cout << *up3 << endl;   // 运行时错误

    shared_ptr<int> sp1 (new int(22));
    shared_ptr<int> sp2 = sp1;

    cout << *sp1 << endl;
    cout << *sp2 << endl;

    sp1.reset();
    cout << *sp2 << endl;
}