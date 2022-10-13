#ifndef AULA_H
#define AULA_H

#include "Date.h"

//Esta uma mistura de ingles com portugues i know :')

//Aula por UC
class Aula{
private:
    std::string _classCode;
    Date _date;
    int _studentsCount;

public:
    //Default construtor
    Aula();

    //Aula construtor
    Aula(std::string classCode, Date date, int studentCount);

    //Setters
    //Sets Class Code
    void setClassCode(std::string classCode);

    //Sets Class date
    void setClassDate(Date date);

    //Getters
    //Returns the Class Code
    std::string getClassCode();

    //Returns the Class Date
    Date getClassDate();
};

#endif