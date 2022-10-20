#include <iostream>
#include "Date.h"

Date::Date() {}
// Date construtor
Date::Date(std::string day, float startingTime, float duration)
{
    // Turns string into int for easier searching later maybe
    _day = Weekdays.at(day);

    // Decided to keep a string version of day for quality of live improvements
    _stringDay = day;

    // Turns float into a better Time format
    _startingTime.minutes = std::modf(startingTime, &_startingTime.hours);
    _startingTime.minutes *= 60;

    // Calcute ending time given a duration
    float endingTime = startingTime + duration;
    _endingTime.minutes = std::modf(endingTime, &_endingTime.hours);
    _endingTime.minutes *= 60;
};

// Sets starting time
void Date::set_StartingTime(Time startingTime)
{
    _startingTime = startingTime;
}

// Sets starting time
void Date::set_StartingTime(float startingTime)
{
    _startingTime.minutes = std::modf(startingTime, &_startingTime.hours);
    _startingTime.minutes *= 60;
}

// Sets ending time
void Date::set_EndingTime(Time endingTime)
{
    _endingTime = endingTime;
}

// Sets ending time
void Date::set_EndingTime(float endingTime)
{
    _endingTime.minutes = std::modf(endingTime, &_endingTime.hours);
    _endingTime.minutes *= 60;
}

// Sets day
void Date::set_Day(int day)
{
    _day = day;
}

// Sets day
void Date::set_Day(std::string day)
{
    _day = Weekdays.at(day);
    _stringDay = day;
}

// Getters

// Returns starting time in Time
Time Date::get_StartingTime_T()
{
    return _startingTime;
}

// Returns starting time in float
float Date::get_StartingTime_f()
{
    return _startingTime.hours + (_startingTime.minutes / 60);
}

// Returns ending time in Time
Time Date::get_EndingTime_T()
{
    return _endingTime;
}

// Returns ending time in float
float Date::get_EndingTime_f()
{
    return _endingTime.hours + (_endingTime.minutes / 60);
}

// Returns day in string
std::string Date::get_Day_s()
{
    return _stringDay;
}

// Returns day in int
int Date::get_Day_i()
{
    return _day;
}

// Other member functionss

bool Date::operator==(Date date) const{
        return (this->_day == date._day && 
        (this->_startingTime.hours == date._startingTime.hours && this->_startingTime.minutes == date._startingTime.minutes) &&
        (this->_endingTime.hours == date._endingTime.hours && this->_endingTime.minutes == date._endingTime.minutes));
}