#include "Uc.h"

Uc::Uc(){};

Uc::Uc(string code_) { code = code_; }

Uc::~Uc(){};

string Uc::get_Code() { return code; }

void Uc::set_Code(string code_) { code = code_; }

void Uc::nova_Turma(Aula turma) {
    turmas.push_back(turma);
}

void Uc::remover_Turma( Aula turma ){
    auto posi = turmas.begin();
    for (long unsigned int i = 0; i < turmas.size(); i++) {
        if (turmas[i] == turma) { turmas.erase(posi); break; }
        posi++;
    }
}

std::vector<Aula> Uc::get_Turmas(){
    return this->turmas;
}

void Uc::setTurmas(std::vector<Aula> turmas){
    this->turmas = turmas;
}

bool Uc::operator==(Uc uc) const{
    return (code == uc.code);
}

