#include "Aula.h"
#include "Date.h"

/**
 * Default construtor da classe Aula.
*/
Aula::Aula(){}

/**
 * Constutor de uma Aula.
 * Recebe apenas o código da turma a que está associada.
*/
Aula::Aula(std::string classCode){
    _classCode = classCode;
}

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
/**
 * Atribui a string passada como atributo ao _classCode da aula.
*/
void Aula::set_ClassCode(std::string classCode)
{
    _classCode = classCode;
}

/**
 * Atribui a data passada como atributo ao atributo _date da aula.
*/
void Aula::set_ClassDate(Date date){
    _date = date;
}

/**
 * Recebe uma string que atribui ao _type da Aula.
*/
void Aula::set_Type(std::string type){
    _type = type;
}

// Getters
/**
 * Retorna o _classcode da aula.
 * @return código da Turma
*/
std::string Aula::get_ClassCode(){
    return _classCode;
}

/**
 * Retorna o atributo _date da aula.
*/
Date Aula::get_ClassDate(){
    return _date;
}

/**
 * Retorna o tipo da aula (T/TP/PL) no formato string.
*/
std::string Aula::get_Type(){
    return _type;
}

/**
 * Duas aulas são iguais se a turma associada for a mesma e se ambas ocorrerem ao mesmo tempo.
*/
bool Aula::operator==(Aula aula) const{
    return (this->_classCode == aula._classCode && this->_type == aula._type);
}

/**
 * Uma turma é menor que outra se e só se o seu _classCode for menor que o _classCode do objeto com que estamos a comparar.
*/
bool Aula::operator< (Aula aula) const{
    return (this->_classCode < aula._classCode);
}

