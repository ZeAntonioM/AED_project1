#include "Aula.h"
#include "Date.h"

// Setters
// Sets Class Code
void Aula::setClassCode(std::string classCode)
{
    _classCode = classCode;
}

// Sets Class date
void Aula::setClassDate(Date date){
    _date = date;
}

// Getters
// Returns the Class Code
std::string Aula::getClassCode(){
    return _classCode;
}

// Returns the Class Date
Date Aula::getClassDate(){
    return _date;
}