#include <iostream>
#include <vector>

using namespace std;


class Cli{
    public:
        char manage_Input(const vector<char> &options_vector, bool allow_back = false /* isto é para decidir se a tab permite ir para trás*/ ) const;
        void startup();
        void student_Tab();
        void uc_Tab() const;
        void class_Tab() const;
        void class_Permute_Tab();
        void general_Listings_Tab() const;
        void get_Student_Schedule();
        void list_Students();
        void list_Students_alpha();
        void list_Students_UP();
        void print_Schedule(int up, int day) const;
        void permute_Between_Students();
        bool permute_Between_Students(int studentUp1, int studentUp2);
        void permute_One_Student();
        bool permute_One_Student(int studentUp1, string classCodeToChangeTo);
};