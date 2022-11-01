#include "Uc.h"

/**
 * Default Constructor da Unidade Curricular.
*/
Uc::Uc(){};

/**
 * Constutor da UC. Recebe como atributo uma string que será atribuida ao seu código.
*/
Uc::Uc(string code) { _code = code; }


/**
 * Destuctor da classe Uc.
*/
Uc::~Uc(){};

/**
 * Retorna o código da UC.
*/
string Uc::get_Code() { return _code; }

/**
 * Recebe como atributo uma string que atribui ao código da UC.
*/
void Uc::set_Code(string code) { _code = code; }

/**
 * Recebe como atributo uma aula e adiciona ao conjunto das turmas da UC.
*/
void Uc::nova_Turma(Aula turma) {
    _turmas.push_back(turma);
}

/**
 * Recebe como atributo uma aula e remove a aula em questão se esta existir no conjunto das turmas da UC.
*/
void Uc::remover_Turma( Aula turma ){
    auto posi = _turmas.begin();
    for (long unsigned int i = 0; i < _turmas.size(); i++) {
        if (_turmas[i] == turma) { _turmas.erase(posi); break; }
        posi++;
    }
}

/**
 * Retorna o conjunto das turmas da UC.
*/
std::vector<Aula> Uc::get_Turmas() const {
    return _turmas;
}

/**
 * Recebe como atributo um vetor relativo ao conjunto de aulas, o qual é atribuido à UC.
*/
void Uc::set_Turmas(std::vector<Aula> turmas){
    _turmas = turmas;
}

/**
 * Duas Ucs são iguas se e apenas se os seus atributos code forem iguais.
*/
bool Uc::operator==(Uc uc) const{
    return (_code == uc._code);
}

bool Uc::operator<(Uc uc1) const{
    return (_code < uc1._code);
}
