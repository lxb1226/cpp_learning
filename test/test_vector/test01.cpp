#include <vector>
#include <string>
#include <iostream>
using namespace std;

// vector emplace_back() 减少一次构造
struct Person
{
    string name;
    int age;
    //初始构造函数
    Person(string p_name, int p_age) : name(std::move(p_name)), age(p_age)
    {
        cout << "初始化构造函数" << endl;
        cout << "I have been constructed" << endl;
    }
    //拷贝构造函数
    Person(const Person &other) : name(std::move(other.name)), age(other.age)
    {   
        cout << "拷贝构造函数" << endl;
        cout << "I have been copy constructed" << endl;
    }
    //转移构造函数
    Person(Person &&other) : name(std::move(other.name)), age(other.age)
    {   
        cout << "移动构造函数" << endl;
        cout << "I have been moved" << endl;
    }
};

int main()
{
    vector<Person> e;
    e.reserve(10);
    cout << "emplace_back:" << endl;
    Person p2("Mike", 36);
    e.emplace_back(p2);
    cout << "---------" << endl;
    e.emplace_back(Person("Mike", 36));
    cout << "---------" << endl;
    e.emplace_back("Jane", 23); //不用构造类对象
    cout << "---------" << endl;

    vector<Person> p;
    p.reserve(10);
    cout << "push_back:" << endl;
    Person p1("Mike", 36);
    p.push_back(p1);
    cout << "---------" << endl;
    p.push_back({"Jane", 23});
    cout << "---------" << endl;
    p.push_back(Person("Mike", 36));

    vector<vector<int>> ans;
    ans.emplace_back(1, 2, 3);


    return 0;
}
//输出结果：
// emplace_back:
// I have been constructed
// push_back:
// I have been constructed
// I am being moved.
