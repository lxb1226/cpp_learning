#include <iostream>
#include <chrono>
#include <ctime>

/*

std::chrono::time_point 表示一个具体时间，如上个世纪80年代、你的生日、今天下午、火车出发时间等，只要它能用计算机时钟表示。
鉴于我们使用时间的情景不同，这个time point具体到什么程度，由选用的单位决定。一个time point必须有一个clock计时。参见clock的说明。
time_point有一个函数time_from_eproch()用来获得1970年1月1日到time_point时间经过的duration。

time_point原型：
template <class Clock, class Duration = typename Clock::duration>  class time_point;

*/
int main()
{
    using namespace std::chrono;

    system_clock::time_point tp_epoch; // epoch value

    time_point<system_clock, duration<int>> tp_seconds(duration<int>(1));

    system_clock::time_point tp(tp_seconds);

    std::cout << "1 second since system_clock epoch = ";
    std::cout << tp.time_since_epoch().count();
    std::cout << " system_clock periods." << std::endl;

    std::time_t tt = system_clock::to_time_t(tp);
    std::cout << "time_point tp is: " << ctime(&tt);
    return 0;
}