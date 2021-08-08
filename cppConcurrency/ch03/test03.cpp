// 清单3.3 std::stack容器适配器接口

#include <deque>
#include <iostream>

template<typename T, typename Container=std::deque<T>>
class stack
{
public:
    explicit stack(const Container&);
    explicit stack(Container&& = Container());
    template<class Alloc> explicit stack(const Alloc&);
    template<class Alloc> stack(const Container&, const Alloc&);
    template<class Alloc> stack(Container&&, const Alloc&);
    template<class Alloc> stack(stack&&, const Alloc&);

    bool empty() const;
    size_t size() const;
    T& top();
    T const& pop() const;
    void push(T const&);
    void push(T&&);
    void pop();
    void swap(stack&&);
    template<class... Args> void emplace(Args&&... args); // c++14的新特性

};

void do_something(int value){
    
}

stack<int> s;
int main(int argc, char* argv[])
{   

    int const value = s.top();
    s.pop();
    do_something(value);
}
