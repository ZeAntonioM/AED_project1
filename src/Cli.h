#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include "Student.h"
#include "Uc.h"


using namespace std;


class Cli{
private:
    bool check_quit;
    set<Student>& _setStudent;
    set<Uc>& _setUc;

public:

    Cli(set<Student>& setStudent, set<Uc>& setUc) : _setStudent(setStudent), _setUc(setUc) {}

    char manage_Input(const vector<char> &options_vector, bool allow_back = false /* isto é para decidir se a tab permite ir para trás*/ );

    //Aux function to wait for user input ("Press any key to continue")
    void wait_for_input();

    void startup();
        //STUDENT TAB
        void student_Tab();
            void get_Student_Schedule();
                void print_Schedule(int up, int day); //TODO
        void list_Students();
            void list_Students_alpha(); //TODO
            void list_Students_UP(); //TODO to finish
        //UC TAB
        void uc_Tab();
            void list_UCs();
               void get_UC_Lectures(); //TODO
             void number_Student_UC(); //TODO

        //CLASS TAB
        void class_Tab();
            void list_Classes();
                void list_All_UCs(); //TODO
                void list_By_UC(); //TODO
            void get_Class_Occupation(); //TODO

        //CLASS PERMUTE TAB
        void class_Permute_Tab();
            void permute_Between_Students();
                bool permute_Between_Students(int studentUp1, int studentUp2); //TODO
            void permute_One_Student();
                bool permute_One_Student(int studentUp1, string classCodeToChangeTo); //TODO
};

#endif