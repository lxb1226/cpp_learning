#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> p(new int(1));
    cout << "unique: " << *p << endl;

    
    shared_ptr<int> q1(p.release());
    cout << "q1: " << *q1 << endl;
    shared_ptr<int> q2(p.get());
    // cout << "q2: " << *q2 << endl;  // segmentation fault
    return 0;
}