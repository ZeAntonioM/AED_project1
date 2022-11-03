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
        Uc(const string& code);
        Uc();
        ~Uc();

        string get_Code();
        void set_Code(const string& code);
        void nova_Turma(const Aula& turma );
        void remover_Turma(const Aula& turma );
        vector<Aula> get_Turmas() const;
        void set_Turmas(const vector<Aula>& turmas);
        bool operator==(const Uc& uc) const;
        bool operator!=(const Uc& uc) const;
        bool operator<(const Uc& uc1) const;


};

#endif