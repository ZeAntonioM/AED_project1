// Humble beginnings

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "Scraper.h"
#include "Aula.h"
#include "Date.h"

using namespace std;


//! READS THE .CSV FILE
int main(){
    Scraper students_classes_scraper = Scraper("csv/students_classes.csv");
    students_classes_scraper.scrape_file();
    vector<tuple<string, vector<string>>> students = students_classes_scraper.get_vector();   // these 2 lines are unnecesary, mas pus pq é bom saber q
    sort(students.begin(), students.end());                                                   // o sort() da smp sort pelo primeiro elemento do tuple
    for (auto s: students){
        cout << get<0>(s) << ": ";
        bool check = false;
        for (auto n : get<1>(s)){
            if (check) cout << ",";
            cout << n;
            check = true;

        }
        cout << "\n";
    }

    //Testing the new classes
    Date date1("Monday", 10.5, 1.5);
    Aula aula1("1LEIC01", date1);

    cout << "/nTesting new Classes/n" << endl;
    cout << date1.getStartingTime_f() << ' ' << date1.getEndingTime_f() << ' ' << date1.getDay_i() << endl; 
    cout << aula1.getClassCode() << ' ' << aula1.getClassDate().getDay_i() << endl;

    return 0;
}
