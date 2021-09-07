#include <iostream>
#include <ratio>
#include <chrono>

/*
由于各种time_point表示方式不同，chrono也提供了相应的转换函数 time_point_cast。
template <class ToDuration, class Clock, class Duration>
time_point<Clock,ToDuration> time_point_cast (const time_point<Clock,Duration>& tp);
*/
int main()
{
    using namespace std::chrono;

    typedef duration<int, std::ratio<60 * 60 * 24>> days_type;
    time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
    std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;

    return 0;
}