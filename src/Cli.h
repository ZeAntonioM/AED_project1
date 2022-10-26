#include <iostream>
#include <vector>

using namespace std;


class Cli{
    public:
        void startup() const;
        void student_Tab() const;
        void uc_Tab() const;
        void class_Permute_Tab() const;
        void general_Listings_Tab() const;
        char manage_Input(vector<char> options_vector, bool allow_back = false /* isto é para decidir se a tab permite ir para trás*/ ) const;

};