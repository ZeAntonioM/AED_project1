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
    cout << students_classes_scraper.get_uc_vector().size() << "\n";
    for (auto i: students_classes_scraper.get_uc_vector()){
        cout << i->get_code() << "    "<< "\n";
        for (auto t: i->getTurmas()){
            Date date = t.getClassDate();
            //cout << t.getClassCode() << t.getType() << " no dia " << date.getDay_s() << " das " << date.getStartingTime_f() << " às " << date.getEndingTime_f() << "\n";
            cout << t.getType();
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
