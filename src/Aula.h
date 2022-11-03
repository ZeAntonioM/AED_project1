#ifndef AULA_H
#define AULA_H

#include "Date.h"

//Esta uma mistura de ingles com portugues i know :')

//Aula por UC
class Aula{
private:
    std::string _classCode;
    Date _date;
    std::string _type;

public:
    //Default construtor
    Aula();

    Aula(const std::string& classCode);

    //Aula construtor
    Aula(const std::string& classCode, const Date& date, const std::string& type);

    //Setters
    //Sets Class Code
    void set_ClassCode(const std::string& classCode);

    //Sets Class date
    void set_ClassDate(const Date& date);

    //Sets Class Student count

    //Sets Class Type
    void set_Type(const std::string& type);
    
    //Getters
    //Returns the Class Code
    std::string get_ClassCode();

    //Returns the Class Date
    Date get_ClassDate();

    //Returns current student count

    //Gets class's type
    std::string get_Type();

    

    //Checks equality between Aula objects
    bool operator==(const Aula& aula) const;
    bool operator<(const Aula& aula) const;
};

#endif