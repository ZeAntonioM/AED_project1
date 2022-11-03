#include "Uc.h"

/**
 * Default Constructor da Unidade Curricular.
*/
Uc::Uc(){};

/**
 * Constutor da UC. Recebe como atributo uma string que será atribuida ao seu código.
*/
Uc::Uc(const string& code) { _code = code; }


/**
 * Destuctor da classe Uc.
*/
Uc::~Uc(){};

/**
 * Retorna o código da UC.
 * @return string com o código da Unidade Curricular
*/
string Uc::get_Code() { return _code; }

/**
 * Recebe como atributo uma string que atribui ao código da UC.
 * @param code string com o código da Uc a definir
*/
void Uc::set_Code(const string& code) { _code = code; }

/**
 * Recebe como atributo uma aula e adiciona ao conjunto das turmas da UC.
 * @param turma objeto do tipo Aula que será adicionado ao vetor como uma nova turma
*/
void Uc::nova_Turma(const Aula& turma) {
    _turmas.push_back(turma);
}

/**
 * Recebe como atributo uma aula e remove a aula em questão se esta existir no conjunto das turmas da UC.
 * @param turma objeto do tipo Aula que será removido do vetor de turmas
*/
void Uc::remover_Turma(const Aula& turma ){
    auto posi = _turmas.begin();
    for (long unsigned int i = 0; i < _turmas.size(); i++) {
        if (_turmas[i] == turma) { _turmas.erase(posi); break; }
        posi++;
    }
}

/**
 * Retorna o conjunto das turmas da UC.
 * @return vetor de objetos do tipo Aula, i.e, as turmas existentes na Uc
*/
std::vector<Aula> Uc::get_Turmas() const {
    return _turmas;
}

/**
 * Recebe como atributo um vetor relativo ao conjunto de aulas, o qual é atribuido à UC.
 * @param turmas vetor de objetos do tipo Aula de modo a definir as turmas da Uc
*/
void Uc::set_Turmas(const std::vector<Aula>& turmas){
    _turmas = turmas;
}

/**
 * Duas Ucs são iguas se e apenas se os seus atributos code forem iguais.
 * @param uc objeto do tipo Uc a ser comparado
 * @return verdadeiro se as Ucs tiverem o mesmo código
*/
bool Uc::operator==(const Uc& uc) const{
    return (_code == uc._code);
}

/**
 * As Unidades Curriculares são ordenadas pelo seu código. Se o código da UC for menor que o código da UC uc1, então a Uc também é "menor"
 * @param uc1 objeto do tipo Uc a ser comparado
 * @return verdadeiro se o código da Uc for menor que o da cc1
*/
bool Uc::operator<(const Uc& uc1) const{
    return (_code < uc1._code);
}
