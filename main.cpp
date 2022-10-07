// Humble beginnings

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    vector<string> seperated_strings;
    ifstream myFile;
    myFile.open("classes.csv");

    while (myFile.good()){
        string line;
        getline(myFile, line);
        cout << line << "\n";

        stringstream ss(line);
        string word;

        while (getline(ss, word, ',')){
            seperated_strings.push_back(word);
        }
        seperated_strings.push_back("\n");

    }
    for (string s: seperated_strings){
        cout << s << " ";
    }
    myFile.close();
}
