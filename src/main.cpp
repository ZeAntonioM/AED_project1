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


//! READS THE .CSV FILE
int main(){

    Scraper students_classes_scraper;
    auto vec1 = students_classes_scraper.scrape_File("src/csv/classes.csv");
    auto uc_set = students_classes_scraper.build_Uc(vec1);
    auto vec2 = students_classes_scraper.scrape_File("src/csv/students_classes.csv");
    auto student_set = students_classes_scraper.build_Students(vec2);
    auto name_vec = students_classes_scraper.build_StudentsName();

/*
    for (auto i : uc_set){
        cout << i.get_Code() << "\n";
        for (auto t: i.get_Turmas()){
            cout << "\t" << t.get_ClassCode() << endl;
        }
    }
    for (auto s: student_set){
        cout << s.get_Up() << endl;
        for (auto u: s.get_Schedule()){
            cout << "\t" << get<0>(u).get_Code() << " " << get<1>(u).get_ClassCode() << get<1>(u).get_Type() << " no dia " << get<1>(u).get_ClassDate().get_Day_s()
                 << " das " << get<1>(u).get_ClassDate().get_StartingTime_f() << " às " << get<1>(u).get_ClassDate().get_EndingTime_f() << endl;

        }
    }

    for (auto i: name_vec){
        cout << i.get_Name() << endl;
    }
*/
    Cli cli(name_vec, student_set, uc_set);
    cli.startup();

    return 0;
}
