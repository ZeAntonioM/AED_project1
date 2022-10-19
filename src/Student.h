#include <iostream>
#include <vector>
#include "Uc.h"
#include "Aula.h"

using namespace std;

class Student{
    private:
        string name;
        int up;
        vector<tuple<Uc, Aula>> schedule;
    public:
        Student(string name_, int up_);
        ~Student();
        string getName();
        int getUp();
        void setName(string name_);
        void setUp(int up_);
        void addUcClass(Uc cadeira, Aula turma);
        void removeUcClass(Uc cadeira, Aula turma);
};
