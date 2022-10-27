#include "Uc.h"

Uc::Uc(){};

Uc::Uc(string code_) { _code = code_; }

Uc::~Uc(){};

string Uc::get_Code() { return _code; }

void Uc::set_Code(string code_) { _code = code_; }

void Uc::nova_Turma(Aula turma) {
    _turmas.push_back(turma);
}

void Uc::remover_Turma( Aula turma ){
    auto posi = _turmas.begin();
    for (long unsigned int i = 0; i < _turmas.size(); i++) {
        if (_turmas[i] == turma) { _turmas.erase(posi); break; }
        posi++;
    }
}

std::vector<Aula> Uc::get_Turmas(){
    return _turmas;
}

void Uc::set_Turmas(std::vector<Aula> turmas){
    _turmas = turmas;
}

bool Uc::operator==(Uc uc) const{
    return (_code == uc._code);
}

bool Uc::operator<(Uc uc1) const{
    return (_code < uc1._code);
}
