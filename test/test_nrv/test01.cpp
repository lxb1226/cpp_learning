#include <iostream>

using namespace std;

class Obj {
 public:
  Obj() { // 构造函数
    std::cout << "in Obj() " << " " << this << std::endl;
  }
  
  Obj(int n) {
    std::cout << "in Obj(int) " << " " << this << std::endl;
  }

  Obj(const Obj &obj) { // 拷贝构造函数
    std::cout << "in Obj(const Obj &obj) " << &obj << " " << this << std::endl;
  }

  Obj &operator=(const Obj &obj) { // 赋值构造函数

    std::cout << "in operator=(const Obj &obj)" << std::endl;
    return *this;
  }

  ~Obj() { // 析构函数
    std::cout << "in ~Obj() " << this << std::endl;
  }

int n;
};

Obj fun() {
  Obj obj;
  // do sth;
  return obj;
}

int main() {
  Obj obj = fun();
  std::cout << "&obj is " << &obj << std::endl;
  return 0;
}
