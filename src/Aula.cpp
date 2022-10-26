#include "Aula.h"
#include "Date.h"

/**
 * Default construtor da classe Aula.
*/
Aula::Aula(){}

/**
 * Contrutor da classe Aula.
 * É atibuida à aula o código da turma a que está associada, uma data associada à mesma e o tipo da aula. 
*/
Aula::Aula(std::string classCode, Date date, std::string type){
        _classCode = classCode;
        _date = date;
        _type = type;
};

// Setters
// Sets Class Code
/**
 * Atribui um código de turma à aula.
*/
void Aula::set_ClassCode(std::string classCode)
{
    _classCode = classCode;
}

// Sets Class date
/**
 * Atribui uma data à aula.
*/
void Aula::set_ClassDate(Date date){
    _date = date;
}

//Sets class student count
/**
 * Atribui a quantidade de alunos incritos nessa aula.
*/
void Aula::set_StudentCount(int studentCount){
    _studentCount = studentCount;
}

// Sets Class Type
/**
 * Atribui um tipo de aula à aula em questão.
*/
void Aula::set_Type(std::string type){
    _type = type;
}

// Getters
// Returns the Class Code
/**
 * Retorna o código da turma associada à aula.
*/
std::string Aula::get_ClassCode(){
    return _classCode;
}

// Returns the Class Date
/**
 * Retorna a data da aula.
*/
Date Aula::get_ClassDate(){
    return _date;
}

//Returns current student Count
/**
 * retorna a quantidade de alunos na turma.
*/
int Aula::get_StudentCount(){
    return _studentCount;
}

/**
 * Retorna o tipo da aula em questão (T, TP, PL, etc..)
*/
std::string Aula::get_Type(){
    return _type;
}

//Checks equality for two Aula objects
/**
 * Duas aulas são iguais se a turma associada for a mesma e se ambas ocorrerem ao mesmo tempo.
*/
bool Aula::operator==(Aula aula) const{
    return (this->_classCode == aula._classCode && this->_type == aula._type);
}
