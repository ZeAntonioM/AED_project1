#include "Uc.h"

/**
 * Default Constructor da Unidade Curricular.
*/
Uc::Uc(){};

/**
 * Constutor da UC. Recebe como atributo uma string que será atribuida ao seu código.
*/
Uc::Uc(string code_) { code = code_; }

/**
 * Destuctor da classe Uc.
*/
Uc::~Uc(){};

/**
 * Retorna o código da UC.
*/
string Uc::get_Code() { return code; }

/**
 * Recebe como atributo uma string que atribui ao código da UC.
*/
void Uc::set_Code(string code_) { code = code_; }

/**
 * Recebe como atributo uma aula e adiciona ao conjunto das turmas da UC.
*/
void Uc::nova_Turma(Aula turma) {
    turmas.push_back(turma);
}

/**
 * Recebe como atributo uma aula e remove a aula em questão se esta existir no conjunto das turmas da UC.
*/
void Uc::remover_Turma( Aula turma ){
    auto posi = turmas.begin();
    for (long unsigned int i = 0; i < turmas.size(); i++) {
        if (turmas[i] == turma) { turmas.erase(posi); break; }
        posi++;
    }
}

/**
 * Retorna o conjunto das turmas da UC.
*/
std::vector<Aula> Uc::get_Turmas(){
    return this->turmas;
}

/**
 * Recebe como atributo um vetor relativo ao conjunto de aulas, o qual é atribuido à UC.
*/
void Uc::set_Turmas(std::vector<Aula> turmas){
    this->turmas = turmas;
}

/**
 * Duas Ucs são iguas se e apenas se os seus atributos code forem iguais.
*/
bool Uc::operator==(Uc uc) const{
    return (code == uc.code);
}

