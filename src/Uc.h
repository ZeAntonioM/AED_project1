#include <iostream>
#include <list>

using namespace std;


class Uc{
    private:
        string code;
        //list<Class> classes;
        string type;
    public:
      //  Uc(string code, list<Class> classes, string type);
        ~Uc();
        string get_code();
        //list<Class> get_classes();
        string get_type();
};