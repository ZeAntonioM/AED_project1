#include "Aula.h"
#include "Date.h"

Aula::Aula(){}

Aula::Aula(std::string classCode){
    _classCode = classCode;
}

Aula::Aula(std::string classCode, Date date, std::string type){
        _classCode = classCode;
        _date = date;
        _type = type;
};

// Setters
// Sets Class Code
void Aula::set_ClassCode(std::string classCode)
{
    _classCode = classCode;
}

// Sets Class date
void Aula::set_ClassDate(Date date){
    _date = date;
}

// Sets Class Type
void Aula::set_Type(std::string type){
    _type = type;
}

// Getters
// Returns the Class Code
std::string Aula::get_ClassCode(){
    return _classCode;
}

// Returns the Class Date
Date Aula::get_ClassDate(){
    return _date;
}

std::string Aula::get_Type(){
    return _type;
}

//Checks equality for two Aula objects
bool Aula::operator==(Aula aula) const{
    return (this->_classCode == aula._classCode && this->_type == aula._type);
}

bool Aula::operator< (Aula aula) const{
    return (this->_classCode < aula._classCode);
}

