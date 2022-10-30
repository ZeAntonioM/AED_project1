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

    void Student::set_Schedule(vector<tuple<Uc,Aula>> schedule){
        this->schedule = schedule;
    }

    vector<tuple<Uc,Aula>> Student::get_Schedule(){
        return schedule;
    }

    bool Student::operator< (Student s1) const{
        return (up < s1.up);
    }


