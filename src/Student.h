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
        string getName();
        string getUp();
        void setName(string name_);
        void setUp(string up_);
        void addUcClass(Uc cadeira, Aula turma);
        void removeUcClass(Uc cadeira, Aula turma);
};
