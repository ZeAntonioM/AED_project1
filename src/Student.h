#include <iostream>

using namespace std;

class Student{
    private:
        string name;
        int up;
    public:
        Student(string name, int up);
        ~Student();
        string get_name();
        int get_up();
};
