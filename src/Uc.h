#include <iostream>
#include "Aula.h"
#include <vector>

using namespace std;


class Uc{
    private:
        string code;

        vector<Aula> turmas;
    public:
        Uc(string code_);
        Uc();
        ~Uc();
        string get_code();
        void set_code(string code_);
        void nova_turma( Aula turma );
        void remover_turma( Aula turma ); 
        vector<Aula> getTurmas();
        void setTurmas(vector<Aula> turmas);
        bool operator==(Uc uc) const;
        void operator* (Uc uc);

};