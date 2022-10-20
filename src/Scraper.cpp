#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include "Scraper.h"

using namespace std;


Scraper::Scraper(){}

Scraper::~Scraper(){}

void Scraper::scrape_files(){
    ifstream file;
    cout << "INITIALIZING SCRAPER \n";
    file.open("/home/work/Desktop/code_file/aed/aed-project1/src/csv/classes.csv");
    cout << file.good() << "   ";

    while(file.good()){
        cout << "ENTERED WHILE \n";
        string line;
        getline (file, line);
        string word;
        stringstream ss(line);
        Date date;
        Aula aula;
        Uc *uc_p;
        Uc uc;
    
        //cout << line << "\n";

        int counter = 1;
        bool check = false;

        while(getline(ss, word, ',')){
            cout << "ENTERED SECOND WHILE \n";
            cout << word << "\n";
            switch(counter){
                case 1:
                    aula.setClassCode(word);
                    cout << "UC CASE 1" <<"\n";
                    break;
                case 2:
                    cout << word << "\n";
                    for (auto u: uc_vector){
                        cout << u.get_code() << " ";
                        if (u.get_code() == word){ cout << "CLASS ALREADY FOUND!!!! \n"; uc_p = &u; check = true;}
                    }
                    if (check){ break;}
                    uc_p = &uc;
                    uc_p->set_code(word);
                    uc_vector.push_back(*uc_p);
                    cout << "UC CASE 2" <<"\n";
                    break;
                case 3:
                    date.setDay(word);
                    cout << "UC CASE 3" <<"\n";
                    break;
                case 4:
                    date.setStartingTime(stof(word));
                    cout << "UC CASE 4" <<"\n";
                    break;
                case 5:
                    date.setEndingTime(stof(word));
                    cout << "UC CASE 5" <<"\n";
                    break;
                case 6:
                    aula.setType(word);
                    cout << "UC CASE 6" <<"\n";
                    break;
            }
            counter++;
        }
        aula.setClassDate(date);
        bool aula_different_check = true;
        cout << uc_p->getTurmas().size() << "\n";

        for (auto a: uc_p->getTurmas()){
            cout << a.getClassCode() << " " << a.getType() << "\n";
            if (aula == a) aula_different_check = false;
        }
        cout << aula_different_check << "\n";
        if (aula_different_check) uc_p->nova_turma(aula);
        cout << uc_p->getTurmas().size() << "\n";

       //cout << uc.get_code() << aula.getClassCode() << date.getDay_s() << date.getStartingTime_f() << date.getEndingTime_f() << "\n";
    }

    file.close();
    file.open("csv/students_classes.csv");

    Student student;

    while (file.good()){
        string line;
        getline(file, line);
        stringstream ss;
        string word;
        string uc_code;

        int counter = 1;
        bool check = false;

        while(getline(ss,word,',')){

            switch(counter){
                case 1:
                    for (auto s: student_vector){
                        if (s.getUp() == word){ student = s; check = true;}
                    }
                    if (check) break;
                    student.setUp(word);
                    student_vector.push_back(student);
                    break;
                case 2:
                    if (check) break;
                    student.setName(word);
                    break;
                case 3:
                    uc_code = word;
                    break;
                case 4:
                    for (auto uc: uc_vector){
                        if (uc_code == uc.get_code()){
                            for (auto turma: uc.getTurmas()){
                                if (word == turma.getClassCode()) student.addUcClass(uc, turma);
                            }
                        }
                    }

            }

            counter++;
        }
    }
}

vector<Student> Scraper::get_student_vector(){
    return student_vector;
}

vector<Uc> Scraper::get_uc_vector(){
    return uc_vector;
}