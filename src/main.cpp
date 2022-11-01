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
    auto set1 = students_classes_scraper.build_Uc(vec1);
    auto vec2 = students_classes_scraper.scrape_File("src/csv/students_classes.csv");
    auto set2 = students_classes_scraper.build_Students(vec2);
    students_classes_scraper.build_StudentsName(set2);
    auto set3 = students_classes_scraper.get_StudentSetName();
/*
    for (auto i : set1){
        cout << i.get_Code() << "\n";
        for (auto t: i.get_Turmas()){
            cout << "\t" << t.get_ClassCode() << endl;
        }
    }
    for (auto s: set2){
        cout << s.get_Up() << endl;
        for (auto u: s.get_Schedule()){
            cout << "\t" << get<0>(u).get_Code() << " " << get<1>(u).get_ClassCode() << get<1>(u).get_Type() << " no dia " << get<1>(u).get_ClassDate().get_Day_s()
                 << " das " << get<1>(u).get_ClassDate().get_StartingTime_f() << " às " << get<1>(u).get_ClassDate().get_EndingTime_f() << endl;

        }
    }

    for (auto i: set3){
        cout << i.get_Name() << endl;
    }
*/
    Cli cli(set3, set2, set1);
    cli.startup();

    return 0;
}
