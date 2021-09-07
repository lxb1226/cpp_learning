#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

/*

std::chrono::steady_clock 为了表示稳定的时间间隔，后一次调用now()得到的时间总是比前一次的值大（这句话的意思其实是，如果中途修改了系统时间，也不影响now()的结果），每次tick都保证过了稳定的时间间隔。
操作有：
now() 获取当前时钟
*/
int main()
{
    using namespace std::chrono;

    steady_clock::time_point t1 = steady_clock::now();

    std::cout << "printing out 1000 starts...\n";
    for (int i = 0; i < 1000; ++i)
        std::cout << "*";
    std::cout << std::endl;

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;

    return 0;
}