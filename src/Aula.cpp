#include "Aula.h"
#include "Date.h"

Aula::Aula(){}

Aula::Aula(std::string classCode, Date date, int studentCount, std::string type){
        _classCode = classCode;
        _date = date;
        _studentCount = studentCount;
        if(type=="T"){
            _type = 0;
        }
        else if(type=="TP"){
            _type = 1;
        }
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
    if(type=="T"){
        _type = 0;
    }
    else if(type=="TP"){
         _type = 1;
    }
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
    if (_type == 0) return "T";
    else return "TP";
}

//Checks equality for two Aula objects
bool Aula::operator==(Aula aula) const{
    return (this->_classCode == aula._classCode && this->_type == aula._type);
}