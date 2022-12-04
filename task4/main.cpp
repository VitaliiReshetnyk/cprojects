/* 10.1, Комп. мат. 1, Решетник.
    Зберігання дати та часу у компактному форматі вікористовуючи мінімально необхідну кількість біт.
    Обчислення різниці часу між двома датами
*/
#include <iostream>
#include "main.hpp"

void Time::inputTime(Date &d)
{
    unsigned int t;
    std::cin >> d.year;
    std::cin >> t;
    d.month = t;
    std::cin >> t;
    d.day = t;
    std::cin >> t;
    d.hour = t;
    std::cin >> t;
    d.minute = t;
    std::cin >> t;
    d.second = t;
}

void Time::outputTime(Date &d)
{
    unsigned int t;
    std::cout << d.year << '.';
    t = d.month;
    std::cout << t << '.';
    t = d.day;
    std::cout << t << ' ';
    t = d.hour;
    std::cout << t << ':';
    t = d.minute;
    std::cout << t << ':';
    t = d.second;
    std::cout << t << std::endl;
}

/* Обчислення номеру Юліанського дня
   формули справедливі для дат після 23 листопада -4713 р.
*/
unsigned int Time::jdn(const Date &d)
{
    unsigned int a = (14 - d.month) / 12;
    unsigned int y = d.year + 4800 - a;
    unsigned int m = d.month + 12 * a - 3;
    return (d.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045);
}

unsigned int Time::seconds(const Date &d)
{
    return (d.hour * 3600 + d.minute * 60 + d.second);
}

int main()
{
    Time t;
    Date d1, d2;
    unsigned long ls1, ls2, df;

    std::cout << "Please input first date (YYYY MM DD HH MM SS): ";
    t.inputTime(d1);

    std::cout << "Please input second date (YYYY MM DD HH MM SS): ";
    t.inputTime(d2);

    ls1 = t.jdn(d1) * 86400 + t.seconds(d1);
    ls2 = t.jdn(d2) * 86400 + t.seconds(d2);
    df = ls2 - ls1;


    std::cout << "   Days = " << df / 86400             << '\n';
    std::cout << "  Hours = " << df % 86400 / 3600      << '\n';
    std::cout << "Minutes = " << df % 86400 % 3600 / 60 << '\n';
    std::cout << "Seconds = " << df % 86400 % 3600 % 60 << std::endl;

    return 0;
}
