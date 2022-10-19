#include "Uc.h"

Uc::Uc(string code_) { code = code_; }

string Uc::get_code() { return code; }

string Uc::set_code(string code_) { code = code; }

void Uc::nova_turma(Aula turma) {
    turmas.push_back(turma);
}

void Uc::remover_turma( Aula turma ){
    auto posi = turmas.begin();
    for (int i = 0; i < turmas.size(); i++) {
        if (turmas[i] == turma) { turmas.erase(posi); break; }
        posi++;
    }
}

