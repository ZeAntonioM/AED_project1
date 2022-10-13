#include <iostream>
#include <vector>
#include "Uc.h"
#include "Aula.h"

using namespace std;

class Student{
    private:
        string name;
        int up;
        vector<tuple<Uc, Aula>> schedule;
    public:
        Student(string name, int up);
        ~Student();
        string get_name();
        int get_up();
};
