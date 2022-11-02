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

int main(){

    Scraper students_classes_scraper;
    auto uc_set = students_classes_scraper.build_Uc(students_classes_scraper.scrape_File("src/csv/classes.csv"));
    auto student_set = students_classes_scraper.build_Students(students_classes_scraper.scrape_File("src/csv/students_classes.csv"));
    auto name_vec = students_classes_scraper.build_StudentsName();
    students_classes_scraper.update_StudentCount();
    auto studentCount_vec = students_classes_scraper.get_StudentCount();

    Cli cli(studentCount_vec, name_vec, student_set, uc_set);
    cli.startup();

    return 0;
}
