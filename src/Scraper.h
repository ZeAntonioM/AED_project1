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

class Scraper
{
private:
    set<Student> _student_Set;
    vector<Student> _student_VectorName;
    set<Uc> _uc_Set;
    vector<tuple<string, string, int>> _student_Count;
    int _columns = 0;
public:
    Scraper();
    ~Scraper();
    vector<string> scrape_File(string filename);
    set<Student> build_Students(vector<string> vector);
    vector<Student> build_StudentsName();
    set<Uc> build_Uc(vector<string> vector);
    void update_StudentCount();
    void read_Permutes();
    set<Student>& get_StudentSet();
    vector<Student>& get_StudentVectorName();
    vector<tuple<string, string, int>>& get_StudentCount();
    set<Uc> get_UcSet();
};

#endif