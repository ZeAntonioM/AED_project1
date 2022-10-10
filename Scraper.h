#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>

using namespace std;

class Scraper
{
private:
    string file;
    vector<tuple<string, vector<string>>> return_vector;
public:
    Scraper(string file_name);
    ~Scraper();
    void scrape_file();
    vector<tuple<string, vector<string>>> get_vector();
};