#pragma once

struct Date
{
    unsigned short year;
    unsigned int  month:4;
    unsigned int    day:5;
    unsigned int   hour:5;
    unsigned int minute:6;
    unsigned int second:6;
};

class Time
{
private:

public:
    unsigned int jdn(const Date &d);
    unsigned int seconds(const Date &d);
    void inputTime(Date &d);
    void outputTime(Date &d);
};
