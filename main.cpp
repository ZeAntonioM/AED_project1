// Humble beginnings

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


//! READS THE .CSV FILE
int main(){
    vector<string> seperated_strings;
    ifstream myFile;
    myFile.open("classes.csv");

    while (myFile.good()){ // reads the classes.csv file until there are no exceptions (including EOF), 0(l) complexity, l being the number of lines in the file
        string line;
        getline(myFile, line);
        cout << line << "\n";

        stringstream ss(line);
        string word;

        while (getline(ss, word, ',')){
            seperated_strings.push_back(word); // seperates all words by the commas and appends them to the vector, 0(w) complexity, w being the strings in each line;
        }
        seperated_strings.push_back("\n");

    }
    for (string s: seperated_strings){  //prints each word on the vector, O(l*w) complexity
        cout << s << " ";
    }
    myFile.close();
}
