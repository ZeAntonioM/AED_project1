#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include "Student.h"
#include "Uc.h"
#include <regex>
#include <tuple>
#include <fstream>
#include <queue>

using namespace std;


class Cli{
private:
    bool check_quit = false;
    vector<tuple<string,string,int>>& _studentCount;
    vector<Student>& _vectorStudent;
    set<Student>& _setStudent;
    set<Uc>& _setUc;
    queue<string> permuteQueue; //UPcode,StudentName,UCcode,ClassCode
    const int _cap = 26;

public:

    Cli(vector<tuple<string,string,int>>& studentCount, vector<Student>& vectorStudent, set<Student>& setStudent, set<Uc>& setUc) :_studentCount(studentCount), _vectorStudent(vectorStudent), _setStudent(setStudent), _setUc(setUc) {}

    char manage_Input(const vector<char> &options_vector, bool allow_back = false /* isto é para decidir se a tab permite ir para trás*/ );

    //Aux function to wait for user input ("Press any key to continue")
    void wait_for_input();

    void startup();
        //STUDENT TAB
        void student_Tab();
            void get_Student_Schedule();
                void print_Schedule(const Student& student, int day);
            void list_Students();
                void list_Students_alpha();
                void list_Students_UP();

        //UC TAB
        void uc_Tab();
            void list_UCs();
            void get_UC_Lectures();
            void number_Student_UC();

        //CLASS TAB
        void class_Tab();
            void list_Classes();
                void list_All_Classes();
                void list_By_UC();
            void get_Class_Occupation(); 

        //CLASS PERMUTE TAB
        void class_Permute_Tab();
            void permute_Between_Students();
                bool permute_Between_Students(const string& studentUp1, const string& studentUp2, const string& ucToSwap);
            void permute_One_Student();
                bool permute_One_Student(const string& studentUp1, const string& ucCode, const string& classCodeToChangeTo);

    void processQueue();

};

#endif