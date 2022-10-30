#ifndef UC_H
#define UC_H


#include <iostream>
#include "Aula.h"
#include <vector>

using namespace std;


class Uc{
    private:
        string _code;

        vector<Aula> _turmas;
    public:
        Uc(string code_);
        Uc();
        ~Uc();

        string get_Code();
        void set_Code(string code_);
        void nova_Turma( Aula turma );
        void remover_Turma( Aula turma ); 
        vector<Aula> get_Turmas();
        void set_Turmas(vector<Aula> turmas);
        bool operator==(Uc uc) const;
        void operator* (Uc uc);
        bool operator<(Uc uc1) const;


};

#endif