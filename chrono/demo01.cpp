#include <iostream>
#include <ratio>
#include <chrono>

/*
https://www.cnblogs.com/jwk000/p/3560086.html
1.Durations
std::chrono::duration 表示一段时间。
template <class Rep, class Period = ratio<1> > class duration;

其中
Rep表示一种数值类型，用来表示Period的数量，比如int，double
Period是ratio类型，用来表示【用秒表示的时间单位】比如second,milisecond
常用的duration<Rep,Period>已经定义好了。
ratio<3600, 1>                hours
ratio<60, 1>                    minutes
ratio<1, 1>                      seconds
ratio<1, 1000>               microseconds
ratio<1, 1000000>         microseconds
ratio<1, 1000000000>    nanosecons

ratio模板的原型：
template <intmax_t N, intmax_t D = 1> class ratio;

N代表分子，D代表分母，所以ratio是一个分数值
注意，我们自己可以定义Period，比如ratio<1, -2>表示单位时间是-0.5秒。

由于各种duration表示不同，chrono库提供了duration_cast类型转换函数。
template <class ToDuration, class Rep, class Period>
 constexpr ToDuration duration_cast (const duration<Rep,Period>& dtn);

*/
int main()
{
    typedef std::chrono::duration<int> seconds_type;
    typedef std::chrono::duration<int, std::milli> milliseconds_type;
    typedef std::chrono::duration<int, std::ratio<60 * 60>> hours_type;

    hours_type h_oneday(24);               // 24h
    seconds_type s_oneday(60 * 60 * 24);   // 86400s
    milliseconds_type ms_oneday(s_oneday); // 86400000ms

    std::cout << h_oneday.count() << " h in 1 day." << std::endl;
    std::cout << s_oneday.count() << " s in 1 day." << std::endl;
    std::cout << ms_oneday.count() << " ms in 1 day." << std::endl;

    seconds_type s_onehour(60 * 60);                                         // 3600s
    hours_type h_onehour(std::chrono::duration_cast<hours_type>(s_onehour)); //
    milliseconds_type ms_onehour(s_onehour);                                 // 3600000ms

    std::cout << s_onehour.count() << "s in 1h." << std::endl;
    std::cout << h_onehour.count() << " h." << std::endl;
    std::cout << ms_onehour.count() << " ms in 1h." << std::endl;

    return 0;
}