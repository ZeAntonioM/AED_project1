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
    Scraper students_classes_scraper;
    students_classes_scraper.scrape_files();
    for (auto i: students_classes_scraper.get_uc_vector()){
        for (auto t: i.get_Turmas()){
            Date date = t.get_ClassDate();
            cout << t.get_ClassCode() << " no dia " << date.get_Day_s() << " das " << date.get_StartingTime_f() << " às " << date.get_EndingTime_f() << "\n";
        }
    }
   
    // Cli cli;
    // cli.startup();

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
