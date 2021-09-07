#include <iostream>
#include <chrono>

// duration还有一个成员函数count() 返回Rep类型的Period数量
int main()
{
    using namespace std::chrono;
    // std::chrono::milliseconds is an instatiation of std::chrono::duration:
    milliseconds foo(1000); // 1 second

    foo *= 60;

    std::cout << "duration (in periods): ";
    std::cout << foo.count() << " milliseconds.\n";

    std::cout << "duration (in seconds): ";
    std::cout << foo.count() * milliseconds::period::num / microseconds::period::den;
    std::cout << " seconds.\n";

    return 0;
}