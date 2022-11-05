#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <vector>
#include "Uc.h"
#include "Aula.h"

using namespace std;

class Student{
    private:
        string _name;
        string _up;
        vector<tuple<Uc, Aula>> schedule;
    public:
        Student(const string& name, const string& up );
        Student();
        ~Student();
        string get_Name() const;
        string get_Up() const;
        void set_Name(const string& name);
        void set_Up(const string& up);
        void add_UcClass(const Uc& cadeira, const Aula& turma);
        void remove_UcClass(const Uc& cadeira, const Aula& turma);
        vector<tuple<Uc,Aula>> get_Schedule() const;
        void set_Schedule(const vector<tuple<Uc,Aula>>& schedule);
        bool operator< (const Student& s1) const;
};
#endif