#include <iostream>
#include "Date.h"

/**
 * Default Constructor da data.
*/
Date::Date() {}

/**
 * Constutor da class Date: 
 * Recebe como atributos o dia em que acontece a aula, a hora a que começa e a sua duração;
 * Calcula o ending time através de um algoritmo de soma entre o tempo inicial e a duração da aula.
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
 * Recebe um atributo no formato Time e atribui o mesmo ao _startingTime.
*/
void Date::set_StartingTime(Time startingTime)
{
    _startingTime = startingTime;
}

/**
 * Recebe um atributo em floating point que é passado para o formato Time e atribuido ao _startingTime.
*/
void Date::set_StartingTime(float startingTime)
{
    _startingTime.minutes = std::modf(startingTime, &_startingTime.hours);
    _startingTime.minutes *= 60;
}

/**
 * Recebe um atributo no formato Time e atribui o mesmo ao _endingTime.
*/
void Date::set_EndingTime(Time endingTime)
{
    _endingTime = endingTime;
}

/**
 * Recebe um atributo em floating point que é passado para o formato Time e atribuido ao _endingTime.
*/
void Date::set_EndingTime(float endingTime)
{
    _endingTime.hours = _startingTime.hours + (int) endingTime;
    _endingTime.minutes = std::modf(endingTime, &_endingTime.hours);
    _endingTime.minutes *= 60;
}

/**
 * Atrubui o argumento passado ao _day.
*/
void Date::set_Day(int day)
{
    _day = day;
}

/**
 * Recebe como atributo usa string que é passada ao seu valor de int referente ao dia. 
 * Esse inteiro é então atribuido a _day.
*/
void Date::set_Day(std::string day)
{
    _day = Weekdays.at(day);
    _stringDay = day;
}

// Getters

/**
 * Retorna o _startingTime no tipo Time.
*/
Time Date::get_StartingTime_T()
{
    return _startingTime;
}


/**
 * Retorna o _startingTime no tipo Float.
*/
float Date::get_StartingTime_f()
{
    return _startingTime.hours + (_startingTime.minutes / 60);
}

/**
 * Retorna o _endingTime no tipo Time.
*/
Time Date::get_EndingTime_T()
{
    return _endingTime;
}

/**
 * Retorna o _endingTime no tipo Float.
*/
float Date::get_EndingTime_f()
{
    return _endingTime.hours + (_endingTime.minutes / 60);
}

/**
 * Retorna _day em string.
*/
// Returns day in string
std::string Date::get_Day_s()
{
    return _stringDay;
}

/**
 * Retorna _day em inteiro.
*/
int Date::get_Day_i()
{
    return _day;
}

/**
 * Para duas datas serem iguais é necesário que:
 *  - Se passem no mesmo dia;
 *  - Começem à mesma hora;
 *  - Terminem à mesma hora.
*/
bool Date::operator==(Date date) const{
        return (this->_day == date._day && 
        (this->_startingTime.hours == date._startingTime.hours && this->_startingTime.minutes == date._startingTime.minutes) &&
        (this->_endingTime.hours == date._endingTime.hours && this->_endingTime.minutes == date._endingTime.minutes));
}