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
    file.open("src/csv/classes.csv");

    while(file.good()){
        line_vector.clear();
        string line;
        getline(file, line);
        stringstream ss(line);
        std::string *word = new std::string();

        while(getline(ss, *word, ',')){
            line_vector.push_back(*word);
        }
        if (line_vector.size() > 6) cout << "LINE READ WITH ERROR";
        
        Date *date = new Date(line_vector[2], stof(line_vector[3]), stof(line_vector[4]));
        Aula *aula = new Aula(line_vector[0], *date, line_vector[5]);
        Uc *uc = new Uc(line_vector[1]);

        for (auto u: uc_vector){
            for (auto t: u->getTurmas())
             cout << "ITEM: " << t.getType() << " and " << line_vector[5] << "\n";
        }

        bool check_uc_doesnt_exist = true;

        for (auto u: uc_vector){
            if (u->get_code() == uc->get_code()){
                check_uc_doesnt_exist = false;

                u->nova_turma(*aula);
            }   
        }

        if (check_uc_doesnt_exist){
            uc->nova_turma(*aula);
            uc_vector.push_back(uc);
        }
    }

    file.close();
    file.open("src/csv/students_classes.csv");

    while(file.good()){
        line_vector.clear();
        Student student;

        string line;
        getline(file, line);
        stringstream ss(line);
        string word;

        while(getline(ss, word, ',')){
            line_vector.push_back(word);
        }

        if(line_vector.size() > 4) cout << "LINE READ WITH ERROR";

        student.setUp(line_vector[0]);
        student.setName(line_vector[1]);

        bool check_student_doesnt_exist = true;

        for (auto s: student_vector){
            if (s.getUp() == student.getUp()){
                check_student_doesnt_exist = false;

                for (auto u: uc_vector){
                    if(u->get_code() == line_vector[2]){
                        for (auto t: u->getTurmas()){
                            if (t.getClassCode() == line_vector[3]) s.addUcClass(*u, t);
                        }
                    }
                }
            }
        }
        
        if (check_student_doesnt_exist){
            for (auto u: uc_vector){
                if(u->get_code() == line_vector[2]){
                    for (auto t: u->getTurmas()){
                        if (t.getClassCode() == line_vector[3]) student.addUcClass(*u, t);
                    }
                }  
            }

            student_vector.push_back(student);
        }
    }
}

vector<Student> Scraper::get_student_vector(){
    return student_vector;
}

vector<Uc*> Scraper::get_uc_vector(){
    return uc_vector;
}