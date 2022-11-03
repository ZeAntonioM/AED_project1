#include "Aula.h"
#include "Date.h"

/**
 * Default construtor da classe Aula.
 * Complexity: O(1)
*/
Aula::Aula(){}

/**
 * Constutor de uma Aula.
 * Recebe apenas o código da turma a que está associada.
 * @param classCode string relativa a turma que se pretende definir
 * Complexity: O(1)
*/
Aula::Aula(const std::string& classCode){
    _classCode = classCode;
}

/**
 * Contrutor da classe Aula.
 * É atibuida à aula o código da turma a que está associada, uma data associada à mesma e o tipo da aula.
 * @param classCode string relativa a turma que se pretende definir
 * @param date objeto do tipo Date referente à data que se pretende definir
 * @param type string relativa ao tipo da aula que se pretende definir
 * Complexity: O(1)
*/
Aula::Aula(const std::string& classCode, const Date& date, const std::string& type){
        _classCode = classCode;
        _date = date;
        _type = type;
};

// Setters
/**
 * Atribui a string passada como atributo ao _classCode da aula.
 * Complexity: O(1)
 * @param classCode string relativa a turma que se pretende definir
*/
void Aula::set_ClassCode(const std::string& classCode)
{
    _classCode = classCode;
}

/**
 * Atribui a data passada como atributo ao atributo _date da aula.
 * Complexity: O(1)
 * @param date objeto do tipo Date referente à data que se pretende definir
*/
void Aula::set_ClassDate(const Date& date){
    _date = date;
}

/**
 * Recebe uma string que atribui ao _type da Aula.
 * Complexity: O(1)
 * @param type string relativa ao tipo da aula que se pretende definir
*/
void Aula::set_Type(const std::string& type){
    _type = type;
}

// Getters
/**
 * Retorna o _classcode da aula.
 * Complexity: O(1)
 * @return código da Turma
*/
std::string Aula::get_ClassCode(){
    return _classCode;
}

/**
 * Retorna o atributo _date da aula.
 * Complexity: O(1)
 * @return objeto do tipo Date indicativo da data da aula em questão
*/
Date Aula::get_ClassDate(){
    return _date;
}

/**
 * Retorna o tipo da aula (T/TP/PL) no formato string.
 * Complexity: O(1)
 * @return string indicativa do tipo da aula em questão
*/
std::string Aula::get_Type(){
    return _type;
}

/**
 * Duas aulas são iguais se a turma associada for a mesma e se ambas ocorrerem ao mesmo tempo.
 * Complexity: O(1)
 * @param aula objeto do tipo Aula que se pretende comparar
 * @return verdadeiro se a turma associada for a mesma e se ambas ocorrerem ao mesmo tempo.
*/
bool Aula::operator==(const Aula& aula) const{
    return (this->_classCode == aula._classCode && this->_type == aula._type);
}

/**
 * Uma turma é menor que outra se e só se o seu _classCode for menor que o _classCode do objeto com que estamos a comparar.
 * Complexity: O(1)
 * @param aula objeto do tipo Aula que se pretende comparar
 * @return verdadeiro se e só se o _classCode for menor que o _classCode do objeto a comparar.
*/
bool Aula::operator< (const Aula& aula) const{
    return (this->_classCode < aula._classCode);
}

