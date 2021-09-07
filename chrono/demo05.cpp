#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

/*
3.Clocks
std::chrono::system_clock 它表示当前的系统时钟，系统中运行的所有进程使用now()得到的时间是一致的。
每一个clock类中都有确定的time_point, duration, Rep, Period类型。

操作有：
now() 当前时间time_point
to_time_t() time_point转换成time_t秒
from_time_t() 从time_t转换成time_point
*/
int main()
{
    using std::chrono::system_clock;

    std::chrono::duration<int, std::ratio<60 * 60 * 24>> one_day(1);

    system_clock::time_point today = system_clock::now();
    system_clock::time_point tomorrow = today + one_day;

    std::time_t tt;

    tt = system_clock::to_time_t(today);
    std::cout << "today is: " << ctime(&tt);

    tt = system_clock::to_time_t(tomorrow);
    std::cout << "tomorrow will be: " << ctime(&tt);

    return 0;
}