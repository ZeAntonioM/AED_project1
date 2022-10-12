#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include "Scraper.h"

using namespace std;


Scraper::Scraper(string file_name)
{
    this->return_vector = return_vector;
    this->file = file_name;
}

Scraper::~Scraper(){}

void Scraper::scrape_file(){
    ifstream file_stream(file);
    while (file_stream.good()){
        string line;
        getline(file_stream, line);

        stringstream ss(line);
        string word;
        string key;
        getline(ss, key, ',');
        vector<string> content;

        while (getline(ss, word,',')){
            content.push_back(word);
        }
        return_vector.push_back(make_tuple(key, content));
    }
    file_stream.close();
}

vector<tuple<string, vector<string>>> Scraper::get_vector(){
    return return_vector;
}