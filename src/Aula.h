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
    int _type;

public:
    //Default construtor
    Aula();

    //Aula construtor
    Aula(std::string classCode, Date date, int studentCount, std::string type);

    //Setters
    //Sets Class Code
    void setClassCode(std::string classCode);

    //Sets Class date
    void setClassDate(Date date);

    //Sets Class Student count
    void setStudentCount(int studentCount);

    //Sets Class Type
    void setType(std::string type);
    
    //Getters
    //Returns the Class Code
    std::string getClassCode();

    //Returns the Class Date
    Date getClassDate();

    //Returns current student count
    int getStudentCount();

    //Gets class's type
    std::string getType();

    

    //Checks equality between Aula objects
    bool operator==(Aula aula) const;
};

#endif