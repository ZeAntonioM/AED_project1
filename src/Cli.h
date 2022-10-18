#include <iostream>
#include <vector>

using namespace std;


class Cli{
    public:
        void startup() const;
        void student_tab() const;
        void uc_tab() const;
        void class_permute_tab() const;
        char manage_input(vector<char> options_vector, bool allow_back = false /* isto é para decidir se a tab permite ir para trás*/ ) const;
};