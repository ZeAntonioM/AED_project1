#include "Student.h"

    Student::Student(string name_ = NULL, string up_ = NULL){
        name = name_;
        up = up_;
    }

    Student::Student(){};

    Student::~Student(){};

    void Student::setName(string name_) { name = name_;}

    void Student::setUp(string up_) { up = up_;}

    string Student::getName() { return name;}

    string Student::getUp() { return up;}  

    void Student::addUcClass(Uc cadeira, Aula turma){
        tuple<Uc,Aula> novaucturma (cadeira, turma);
        schedule.push_back(novaucturma);
    }

    void Student::removeUcClass(Uc cadeira, Aula turma){
        tuple<Uc, Aula> UCTurmRemove (cadeira, turma);
        auto posi = schedule.begin();
        for (long unsigned int i = 0; i < schedule.size(); i++) {
            if (schedule[i] == UCTurmRemove) { schedule.erase(posi); break; }
            posi++;
        }
    }




