#include "Aula.h"
#include "Date.h"

Aula::Aula(){}

Aula::Aula(std::string classCode, Date date, std::string type){
        _classCode = classCode;
        _date = date;
        _type = type;
};

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

//Sets class student count
void Aula::setStudentCount(int studentCount){
    _studentCount = studentCount;
}

// Sets Class Type
void Aula::setType(std::string type){
    _type = type;
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

//Returns current student Count
int Aula::getStudentCount(){
    return _studentCount;
}

std::string Aula::getType(){
    return _type;
}

//Checks equality for two Aula objects
bool Aula::operator==(Aula aula) const{
    return (this->_classCode == aula._classCode && this->_type == aula._type);
}
