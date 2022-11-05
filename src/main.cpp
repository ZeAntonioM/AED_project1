// Humble beginnings

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
#include "Scraper.h"
#include "Aula.h"
#include "Date.h"
#include "Cli.h"

using namespace std;

int main()
{

    Scraper students_classes_scraper("src/csv/students_classes.csv", "src/csv/classes.csv");

    auto uc_set = students_classes_scraper.get_UcSet();
    auto student_set = students_classes_scraper.get_StudentSet();
    auto name_vec = students_classes_scraper.get_StudentVectorName();
    auto studentCount_vec = students_classes_scraper.get_StudentCount();

    Cli cli(studentCount_vec, name_vec, student_set, uc_set);
    cli.startup();

    return 0;
}
