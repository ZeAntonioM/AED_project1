#include "Student.h"

    Student::Student(string name = NULL, string up = NULL){
        _name = name;
        _up = up;
    }

    Student::Student(){};

    Student::~Student(){};

    void Student::set_Name(string name) { _name = name;}

    void Student::set_Up(string up) { _up = up;}

    string Student::get_Name() const { return _name;}

    string Student::get_Up() const { return _up;}

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
        return (_up < s1._up);
    }


