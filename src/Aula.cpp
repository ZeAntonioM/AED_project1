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
 * Atribui a string passada como atributo ao _classCode da aula.
*/
void Aula::set_ClassCode(std::string classCode)
{
    _classCode = classCode;
}

// Sets Class date
/**
 * Atribui a data passada como atributo ao atributo _date da aula.
*/
void Aula::set_ClassDate(Date date){
    _date = date;
}

//Sets class student count
/**
 * Faz com que o inteiro passado como atributo seja o número de estudantes inscritos para frequentar a aula.
*/
void Aula::set_StudentCount(int studentCount){
    _studentCount = studentCount;
}

// Sets Class Type
/**
 * Recebe uma string que atribui ao _type da Aula.
*/
void Aula::set_Type(std::string type){
    _type = type;
}

// Getters
// Returns the Class Code
/**
 * Retorna o _classcode da aula.
*/
std::string Aula::get_ClassCode(){
    return _classCode;
}

// Returns the Class Date
/**
 * Retorna o atributo _date da aula.
*/
Date Aula::get_ClassDate(){
    return _date;
}

//Returns current student Count
/**
 * Retorna a quantidade de alunos insritos para frequentar a aula.
*/
int Aula::get_StudentCount(){
    return _studentCount;
}

/**
 * Retorna o tipo da aula (T/TP/PL) no formato string.
*/
std::string Aula::get_Type(){
    return _type;
}

//Checks equality for two Aula objects
/**
 * Duas aulas são iguais se a turma associada for a mesma e se ambas ocorrerem ao mesmo tempo.
*/
bool Aula::operator==(Aula aula) const{
    return (this->_classCode == aula._classCode && this->_date == aula._date);
}
