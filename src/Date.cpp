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
void Date::setStartingTime(Time startingTime)
{
    _startingTime = startingTime;
}

// Sets starting time
void Date::setStartingTime(float startingTime)
{
    _startingTime.minutes = std::modf(startingTime, &_startingTime.hours);
    _startingTime.minutes *= 60;
}

// Sets ending time
void Date::setEndingTime(Time endingTime)
{
    _endingTime = endingTime;
}

// Sets ending time
void Date::setEndingTime(float endingTime)
{
    _endingTime.minutes = std::modf(endingTime, &_endingTime.hours);
    _endingTime.minutes *= 60;
}

// Sets day
void Date::setDay(int day)
{
    _day = day;
}

// Sets day
void Date::setDay(std::string day)
{
    _day = Weekdays.at(day);
}

// Getters

// Returns starting time in Time
Time Date::getStartingTime_T()
{
    return _startingTime;
}

// Returns starting time in float
float Date::getStartingTime_f()
{
    return _startingTime.hours + (_startingTime.minutes / 60);
}

// Returns ending time in Time
Time Date::getEndingTime_T()
{
    return _endingTime;
}

// Returns ending time in float
float Date::getEndingTime_f()
{
    return _endingTime.hours + (_endingTime.minutes / 60);
}

// Returns day in string
std::string Date::getDay_s()
{
    return _stringDay;
}

// Returns day in int
int Date::getDay_i()
{
    return _day;
}

// Other member functionss