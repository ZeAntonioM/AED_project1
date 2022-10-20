#include "Uc.h"

Uc::Uc(){};

Uc::Uc(string code_) { code = code_; }

Uc::~Uc(){};

string Uc::get_code() { return code; }

void Uc::set_code(string code_) { code = code_; }

void Uc::nova_turma(Aula turma) {
    turmas.push_back(turma);
}

void Uc::remover_turma( Aula turma ){
    auto posi = turmas.begin();
    for (long unsigned int i = 0; i < turmas.size(); i++) {
        if (turmas[i] == turma) { turmas.erase(posi); break; }
        posi++;
    }
}

std::vector<Aula> Uc::getTurmas(){
    return this->turmas;
}

bool Uc::operator==(Uc uc) const{
    return (code == uc.code);
}

