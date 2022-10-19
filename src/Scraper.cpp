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
    file.open("students_classes.csv");
    while(file.good()){

        string line;
        getline(file, line);
        stringstream ss(line);
        string word;
        int counter = 1;

        while (getline(ss, word, ',')){
            bool check_continue = false;

            if (counter == 1){
                for(auto s: return_vector){
                    if (s.getUp() == word) check_continue = true;
                }
            }
            if (check_continue) continue;

            counter++;
        }
        
    }

}

vector<Student> Scraper::get_vector(){
    return return_vector;
}