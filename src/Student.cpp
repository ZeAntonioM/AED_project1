#include "Student.h"

    Student::Student(string name_ = NULL, string up_ = NULL){
        name = name_;
        up = up_;
    }

    Student::Student(){};

    Student::~Student(){};

    void Student::set_Name(string name_) { name = name_;}

    void Student::set_Up(string up_) { up = up_;}

    string Student::get_Name() { return name;}

    string Student::get_Up() { return up;}  

    void Student::add_UcClass(Uc cadeira, Aula turma){
        tuple<Uc,Aula> novaucturma (cadeira, turma);
        schedule.push_back(novaucturma);
    }

    void Student::remove_UcClass(Uc cadeira, Aula turma){
        tuple<Uc, Aula> UCTurmRemove (cadeira, turma);
        auto posi = schedule.begin();
        for (long unsigned int i = 0; i < schedule.size(); i++) {
            if (schedule[i] == UCTurmRemove) { schedule.erase(posi); break; }
            posi++;
        }
    }




