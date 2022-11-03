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
 * @param day string relativa ao dia a definir
 * @param duration float referente á hora de começo
 * @param startingTime float referente á dureção
*/
Date::Date(const std::string& day, const float& startingTime, const float& duration)
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
 * @param startingTime objeto do tipo Time referente à hora de começo
*/
void Date::set_StartingTime(const Time& startingTime)
{
    _startingTime = startingTime;
}

/**
 * Recebe um atributo em floating point que é passado para o formato Time e atribuido ao _startingTime.
 * @param startingTime objeto float referente à hora de começo
*/
void Date::set_StartingTime(const float& startingTime)
{
    _startingTime.minutes = std::modf(startingTime, &_startingTime.hours);
    _startingTime.minutes *= 60;
}

/**
 * Recebe um atributo no formato Time e atribui o mesmo ao _endingTime.
 * @param endingTime objeto do tipo Time referente à hora de término
*/
void Date::set_EndingTime(const Time& endingTime)
{
    _endingTime = endingTime;
}

/**
 * Recebe um atributo em floating point que é passado para o formato Time e atribuido ao _endingTime.
 * @param endingTime objeto float referente à hora de término
*/
void Date::set_EndingTime(const float& endingTime)
{
    _endingTime.hours = _startingTime.hours + (int) endingTime;
    _endingTime.minutes = std::modf(endingTime, &_endingTime.hours);
    _endingTime.minutes *= 60;
}

/**
 * Atrubui o argumento passado ao _day.
 * @param day int referente ao dia a ser definido
*/
void Date::set_Day(const int& day)
{
    _day = day;
}

/**
 * Recebe como atributo usa string que é passada ao seu valor de int referente ao dia. 
 * Esse inteiro é então atribuido a _day.
 * @param day string referente ao dia a ser definido
*/
void Date::set_Day(const std::string& day)
{
    _day = Weekdays.at(day);
    _stringDay = day;
}

// Getters

/**
 * Retorna o _startingTime no tipo Time.
 * @return objeto do tipo Time referente à hora de começo
*/
Time Date::get_StartingTime_T() const
{
    return _startingTime;
}


/**
 * Retorna o _startingTime no tipo Float.
 * @return float referente à hora de começo
*/
float Date::get_StartingTime_f() const
{
    return _startingTime.hours + (_startingTime.minutes / 60);
}

/**
 * Retorna o _endingTime no tipo Time.
 * @return objeto do tipo Time referente à hora de término
*/
Time Date::get_EndingTime_T() const
{
    return _endingTime;
}

/**
 * Retorna o _endingTime no tipo Float.
 * @return float referente à hora de término
*/
float Date::get_EndingTime_f() const
{
    return _endingTime.hours + (_endingTime.minutes / 60);
}

/**
 * Retorna _day em string.
 * @return string com o dia da semana referente
*/
std::string Date::get_Day_s() const
{
    return _stringDay;
}

/**
 * Retorna _day em inteiro.
 * @return int com o dia da semana referente
*/
int Date::get_Day_i() const
{
    return _day;
}

/**
 * Para duas datas serem iguais é necesário que:
 *  - Se passem no mesmo dia;
 *  - Começem à mesma hora;
 *  - Terminem à mesma hora.
 *  @param date objeto do tipo Date a comparar
 *  @return verdadeiro se as condições necessárias se confirmarem
*/
bool Date::operator==(const Date& date) const{
    return (this->_day == date._day && 
        (this->_startingTime.hours == date._startingTime.hours && this->_startingTime.minutes == date._startingTime.minutes) &&
        (this->_endingTime.hours == date._endingTime.hours && this->_endingTime.minutes == date._endingTime.minutes));
}

bool Date::collides(const Date& d2) const{
    return (this->get_Day_i() == d2.get_Day_i()) && (((this->get_StartingTime_f() > d2.get_StartingTime_f()) && (this->get_StartingTime_f() < d2.get_EndingTime_f())) ||
            ((this->get_EndingTime_f() > d2.get_StartingTime_f()) && (this->get_EndingTime_f() < d2.get_EndingTime_f())) ||
            (*this == d2));
}
}