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
        bool check_To_Brake = false;
        set<Student>& _setStudent;
        set<Uc>& _setUc;

    public:

        Cli(set<Student>& setStudent, set<Uc>& setUc) : _setStudent(setStudent), _setUc(setUc) {}

        char manage_Input(const vector<char> &options_vector, bool allow_back = false /* isto é para decidir se a tab permite ir para trás*/ );

        //TODO aux function to wait for user input ("Press any key to continue")
        static void wait_for_input();

        void startup();
            //STUDENT TAB
            void student_Tab();
                void get_Student_Schedule();
                    void print_Schedule(int up, int day);
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
                    void list_All_UCs();
                    void list_By_UC();
                void get_Class_Occupation();

            //CLASS PERMUTE TAB
            void class_Permute_Tab();
                void permute_Between_Students();
                    bool permute_Between_Students(int studentUp1, int studentUp2);
                void permute_One_Student();
                    bool permute_One_Student(int studentUp1, string classCodeToChangeTo);
};

#endif