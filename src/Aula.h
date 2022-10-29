#ifndef AULA_H
#define AULA_H

#include "Date.h"

//Esta uma mistura de ingles com portugues i know :')

//Aula por UC
class Aula{
private:
    std::string _classCode;
    Date _date;
    int _studentCount;
    std::string _type;

public:
    //Default construtor
    Aula();

    Aula(std::string classCode);

    //Aula construtor
    Aula(std::string classCode, Date date, std::string type);

    //Setters
    //Sets Class Code
    void set_ClassCode(std::string classCode);

    //Sets Class date
    void set_ClassDate(Date date);

    //Sets Class Student count
    void set_StudentCount(int studentCount);

    //Sets Class Type
    void set_Type(std::string type);
    
    //Getters
    //Returns the Class Code
    std::string get_ClassCode();

    //Returns the Class Date
    Date get_ClassDate();

    //Returns current student count
    int get_StudentCount();

    //Gets class's type
    std::string get_Type();

    

    //Checks equality between Aula objects
    bool operator==(Aula aula) const;
    bool operator<(Aula aula) const;
};

#endif