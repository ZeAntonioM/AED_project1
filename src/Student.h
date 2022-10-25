#include <iostream>
#include <vector>
#include "Uc.h"
#include "Aula.h"

using namespace std;

class Student{
    private:
        string name;
        string up;
        vector<tuple<Uc, Aula>> schedule;
    public:
        Student(string name_, string up_ );
        Student();
        ~Student();
        string get_Name();
        string get_Up();
        void set_Name(string name_);
        void set_Up(string up_);
        void add_UcClass(Uc cadeira, Aula turma);
        void remove_UcClass(Uc cadeira, Aula turma);
};
