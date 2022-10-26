#include <iostream>
#include "Date.h"

/**
 * Default Constructor da data.
*/
Date::Date() {}

/**
 * Constutor da class Date: 
 * Recebe como atributos o dia em que acontece a aula, a hora a que começa e a sua duração;
 * Calcula o tempo de sim através de um algoritmo de soma entre o tempo inicial e a duração da aula.
*/
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

/**
 * Atribui uma starting time através de um Time.
*/
// Sets starting time
void Date::set_StartingTime(Time startingTime)
{
    _startingTime = startingTime;
}

/**
 * Atribui um starting time através de uma string.
*/
// Sets starting time
void Date::set_StartingTime(float startingTime)
{
    _startingTime.minutes = std::modf(startingTime, &_startingTime.hours);
    _startingTime.minutes *= 60;
}

/**
 * Atribui um ending time através de um Time.
*/
// Sets ending time
void Date::set_EndingTime(Time endingTime)
{
    _endingTime = endingTime;
}

/**
 * Atribui um ending time através de uma string.
*/
// Sets ending time
void Date::set_EndingTime(float endingTime)
{
    _endingTime.hours = _startingTime.hours + (int) endingTime;
    _endingTime.minutes = std::modf(endingTime, &_endingTime.hours);
    _endingTime.minutes *= 60;
}

/**
 * Altera o atributo day através de um inteiro.
*/
// Sets day
void Date::set_Day(int day)
{
    _day = day;
}

/**
 * Altera o atributo day através de uma string.
*/
// Sets day
void Date::set_Day(std::string day)
{
    _day = Weekdays.at(day);
    _stringDay = day;
}

// Getters

/**
 * Retorna o starting time no tipo Time.
*/
// Returns starting time in Time
Time Date::get_StartingTime_T()
{
    return _startingTime;
}


/**
 * Retorna o starting time no tipo Float.
*/
// Returns starting time in float
float Date::get_StartingTime_f()
{
    return _startingTime.hours + (_startingTime.minutes / 60);
}

/**
 * Retorna o ending tome no tipo Time.
*/
// Returns ending time in Time
Time Date::get_EndingTime_T()
{
    return _endingTime;
}

/**
 * Retorna o ending time no tipo Float.
*/
// Returns ending time in float
float Date::get_EndingTime_f()
{
    return _endingTime.hours + (_endingTime.minutes / 60);
}

/**
 * Retorna o dia em string.
*/
// Returns day in string
std::string Date::get_Day_s()
{
    return _stringDay;
}

/**
 * Retorna o dia em inteiro.
*/
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