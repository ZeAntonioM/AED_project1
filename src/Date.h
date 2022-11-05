#ifndef DATE_H
#define DATE_H

#include <string>
#include <map>
#include <math.h>

struct Time
{
    float hours;
    float minutes;
};

static std::map<std::string, int> Weekdays = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};

class Date
{
private:
    int _day{};
    std::string _stringDay;

    Time _startingTime = {0, 0};
    Time _endingTime = {0, 0};

public:
    Date();
    Date(const std::string& day, const float& startingTime, const float& duration);
    void set_StartingTime(const Time& startingTime);
    void set_StartingTime(const float& startingTime);
    void set_EndingTime(const Time& endingTime);
    void set_EndingTime(const float& endingTime);
    void set_Day(const int& day);
    void set_Day(const std::string& day);
    Time get_StartingTime_T() const;
    float get_StartingTime_f() const;
    Time get_EndingTime_T() const;
    float get_EndingTime_f() const;
    std::string get_Day_s() const;
    int get_Day_i() const;
    bool collides(const Date& d2) const;
    bool operator== (const Date& date) const;
};

#endif
