#ifndef SCRAPER_H
#define SCRAPER_H

#include <iostream>
#include <tuple>
#include <fstream>
#include <sstream>
#include <set>
#include "Student.h"
#include "Aula.h"
#include "Date.h"
#include "Uc.h"

using namespace std;

struct reSort{
    bool operator() (Student s1, Student s2){
        return (s1.get_Name() <= s2.get_Name());
    }
};

class Scraper
{
private:
    set<Student> _student_Set;
    set<Student, reSort> _student_SetName;
    set<Uc> _uc_Set;
    int _columns = 0;
public:
    Scraper();
    ~Scraper();
    vector<string> scrape_File(string filename);
    set<Student> build_Students(vector<string> vector);
    void build_StudentsName(set<Student>);
    set<Uc> build_Uc(vector<string> vector);
    set<Student> get_StudentSet();
    set<Student, reSort> get_StudentSetName(){return _student_SetName;}
    set<Uc> get_UcSet();
};

#endif