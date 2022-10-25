#include <iostream>
#include <tuple>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Aula.h"
#include "Date.h"

using namespace std;

class Scraper
{
private:
    vector<Student> student_vector = {};
    vector<Uc*> uc_vector = {};
    vector<string> line_vector;
public:
    Scraper();
    ~Scraper();
    void scrape_Files();
    vector<Student> get_Student_Vector();
    vector<Uc*> get_Uc_Vector();
};