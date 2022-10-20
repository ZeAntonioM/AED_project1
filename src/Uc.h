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
        string get_Code();
        void set_Code(string code_);
        void nova_Turma( Aula turma );
        void remover_Turma( Aula turma ); 
        vector<Aula> get_Turmas();
        bool operator==(Uc uc) const;
        void operator* (Uc uc);

};