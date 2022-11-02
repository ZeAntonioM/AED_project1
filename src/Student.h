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
        Student(string name, string up );
        Student();
        ~Student();
        string get_Name() const;
        string get_Up() const;
        void set_Name(string name);
        void set_Up(string up);
        void add_UcClass(Uc cadeira, Aula turma);
        void remove_UcClass(Uc cadeira, Aula turma);
        vector<tuple<Uc,Aula>>& get_Schedule();
        void set_Schedule(vector<tuple<Uc,Aula>> schedule);
        bool operator< (Student s1) const;
};
#endif