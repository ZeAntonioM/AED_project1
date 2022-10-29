// Humble beginnings

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "Scraper.h"
#include "Aula.h"
#include "Date.h"
#include "Cli.h"

using namespace std;


//! READS THE .CSV FILE
int main(){
    /*
    Scraper students_classes_scraper;
    auto vec1 = students_classes_scraper.scrape_File("src/csv/classes.csv");
    auto set1 = students_classes_scraper.build_Uc(vec1);
    auto vec2 = students_classes_scraper.scrape_File("src/csv/students_classes.csv");
    auto set2 = students_classes_scraper.build_Students(vec2);
    
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
 */
   
    Cli cli;
    cli.startup();

    //Testing the new classes
    /*
    Date date1 = Date("Monday", 10.5, 1.5);
    Aula aula1 = Aula("1LEIC01", date1, 25, "T");

    cout << "/nTesting new Classes/n" << endl;
    cout << date1.getStartingTime_f() << ' ' << date1.getEndingTime_f() << ' ' << date1.getDay_i() << endl; 
    cout << aula1.getClassCode() << ' ' << aula1.getClassDate().getDay_i() << ' ' << aula1.getStudentCount() << endl;

    */
    return 0;
}
