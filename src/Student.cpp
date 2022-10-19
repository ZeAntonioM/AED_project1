#include "Student.h"

    Student::Student(string name_, int up_){
        name = name_;
        up = up_;
    }

    void Student::setName(string name_) { name = name_;}

    void Student::setUp(int up_) { up = up_;}

    string Student::getName() { return name;}

    int Student::getUp() { return up;}  

    void Student::addUcClass(Uc cadeira, Aula turma){
        tuple<Uc,Aula> novaucturma (cadeira, turma);
        schedule.push_back(novaucturma);
    }

    void Student::removeUcClass(Uc cadeira, Aula turma){
        tuple<Uc, Aula> UCTurmRemove (cadeira, turma);
        auto posi = schedule.begin();
        for (int i = 0; i < schedule.size(); i++) {
            if (schedule[i] == UCTurmRemove) { schedule.erase(posi); break; }
            posi++;
        }
    }




