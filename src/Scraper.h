#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Uc.h"
#include "Aula.h"
#include "Date.h"

using namespace std;

class Scraper
{
private:
    vector<Student> return_vector;
public:
    Scraper();
    ~Scraper();
    void scrape_files();
    vector<Student> get_vector();
};