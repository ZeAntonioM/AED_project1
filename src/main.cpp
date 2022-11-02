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
    auto uc_set = students_classes_scraper.build_Uc(students_classes_scraper.scrape_File("src/csv/classes.csv"));
    auto student_set = students_classes_scraper.build_Students(students_classes_scraper.scrape_File("src/csv/students_classes.csv"));
    auto name_vec = students_classes_scraper.build_StudentsName();
    students_classes_scraper.update_StudentCount();
    auto studentCount_vec = students_classes_scraper.get_StudentCount();
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

    cout << students_classes_scraper.get_StudentCount().size();
    for (auto p: students_classes_scraper.get_StudentCount()){
        
        cout << get<0>(p) << " " << get<1>(p) << ": " << get<2>(p) << endl;
    }
    */
    Cli cli(studentCount_vec, name_vec, student_set, uc_set);
    cli.startup();

    return 0;
}
