#include <iostream>
#include <list>
#include "Aula.cpp"

using namespace std;


class Uc{
    private:
        string code;

        vector<Aula> turmas;
    public:
        Uc(string code_);
        ~Uc();
        string get_code();
        string set_code(string code_);
        void nova_turma( Aula turma );
        void remover_turma( Aula turma ); 

};