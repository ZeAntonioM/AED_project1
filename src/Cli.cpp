#include <iostream>
#include <vector>
#include "Cli.h"

using namespace std;

char Cli::manage_Input(const vector<char> &options_vector, bool allow_back) const
{
     char option;

     while (true)
     {
          cout << "\n"
               << "Option:   ";
          cin >> option;
          bool check_to_break = false;

          if (option == 'Q' || option == 'q'){system("clear"); break;} // quit the tool

          // validar o input entre as 3 opções (infelizmente um input tp 14827634 é válido pq o primeiro caracter é válido, é oq é irmauns)
          for (char i : options_vector)
          {
               if (option == i || (allow_back && (option == 'b' || option == 'B'))){  // só permitir o 'B' se assim for dito no parametro
                    check_to_break = true;
               }
          }

          cin.ignore(INT16_MAX, '\n'); // limpar o buffer para não invalidar uma vez por cada caracter de input, caso escrevam mais q um
     

          if (check_to_break) break;  // uso o check to break para sair do while loop e não do for :)

          cout << "Invalid Input, please try again"
               << "\n";
     }

     return option;
}

void Cli::startup()
{
    char option;
    system("clear"); // limpar o terminal ao invocar o comando da shell "clear"
    cout << "//////////////   Schedule Tool   //////////////"
         << "\n"
         << "Select one of the following options:"
         << "\n"
         << "[1] - Search for student or student information"
         << "\n"
         << "[2] - Search for UC or UC information"
         << "\n"
         << "[3] - Search for Class or Class information"
         << "\n"
         << "[4] - Class permute"
         << "\n"
         << "[Q] - Quit tool"
         << "\n";

    vector<char> v = {'1','2','3','4'};
    option = manage_Input(v, false);

    switch (option)
    {
    case '1':
        student_Tab(); //TODO acabar a list_Students() e get_Student_Schedule()
        break;
    case '2':
        uc_Tab();
        break;
    case '3':
        class_Tab();    //TODO implement permutation functions
        break;
    case '4':
        class_Permute_Tab();    //TODO everything
        break;
    }

}
void Cli::student_Tab()
{
    system("clear"); // limpar o terminal ao invocar o comando da shell "clear"
    cout << "////////////   Students Information     ////////////"
         << "\n"
         << "Select one of the following options:"
         << "\n"
         << "[1] - Get schedule"
         << "\n"
         << "[2] - List Students"
         << "\n"
         << "[B] - Go back to main menu"
         << "\n"
         << "[Q] - Quit tool"
         << "\n";

    vector<char> options = {'1','2','b','B'};
    char option = manage_Input(options, true);

    switch (option)
    {
        case '1':
            get_Student_Schedule();
            break;
        case '2':
            list_Students();
            break;
        case 'b':
            startup();
            break;
        case 'B':
            startup();
            break;
    }
}

void Cli::uc_Tab() const{
     system("clear");
     string year;

     cout << "Introduce the academic year: ";     
     cin >> year;

     //Mostrar a lista de ucs para o ano academico
     //int i; for (Uc u: lista de ucs) i++ if u.year == year cout << [ << i << ] - << uc.name << "\n";


     cout << "///////////    Unidades Curriculares    ///////////"
          << "\n"
          << "Select one of the following options:"
          << "\n"
          << "[1] - Get UC Lectures"
          << "\n"
          << "[2] - List UCs"
          << "\n"
          << "[B] - Go back to main menu"
          << "\n"
          << "[Q] - Quit tool"
          << "\n";
}

void Cli::general_Listings_Tab() const{
     system("clear");

     cout << "///////////    General Listings     ///////////"
          << "\n"
          << "Select one of the following options:"
          << "\n"
          << "List by:"
          << "\n"
          << "[1] - Student's Name (alphabetical)"
          << "\n"
          << "[2] - Student's Number"
          << "\n"
          << "[3] - Students in given UC"
          << "\n"
          << "[3] - UC Occupation"
          << "\n"
          << "[4] - Year Occupation"
          << "\n"
          << "[5] - Class Occupation (Not Lecture)"
          << "[B] - Go back to main menu"
          << "\n"
          << "[Q] - Quit tool"
          << "\n";

}

void Cli::class_Permute_Tab(){
    system("clear");

    cout << "////////////   Class Permute   ////////////"
         << "\n"
         << "Choose how to permute:"
         << "\n"
         << "[1] - Between two students"
         << "\n"
         << "[2] - One student only"
         << "\n"
         << "[B]- Go to previous menu"
         << "\n"
         << "[Q] - Quit tool"
         << "\n";

    vector<char> options = {'1','2','b','B'};
    char option = manage_Input(options, true);

    switch (option)
    {
        case '1':
            permute_Between_Students();
            break;
        case '2':
            permute_One_Student();
            break;
        case 'b':
            student_Tab();
            break;
        case 'B':
            student_Tab();
            break;
    }
}
//TODO finish this function
void Cli::get_Student_Schedule() {

    system("clear");

    int up;
    cout << "\n" << "Introduce the student's UP code (only the number): ";
    cin >> up;
    cout << "\n";

    // função para verificar se o estudante existe

    // o plano é para substituir o up no printf pelo nome do estudante
    // mas ainda não os tenho ent vai ficar o up por agr

    cout << "////////////   Student up" << up << "   ////////////"
         << "\n"
         << "Choose a day:"
         << "\n"
         << "[1] - Monday"
         << "\n"
         << "[2] - Tuesday"
         << "\n"
         << "[3] - Wednesday"
         << "\n"
         << "[4] - Thursday"
         << "\n"
         << "[5] - Friday"
         << "\n"
         << "[B]- Go to previous menu"
         << "\n"
         << "[Q] - Quit tool"
         << "\n";

    vector<char> options = {'1','2','3', '4', '5','b','B'};
    char option = manage_Input(options, true);

    switch (option)
    {
        case '1':
            print_Schedule(up, 1);
            break;
        case '2':
            print_Schedule(up, 2);
            break;
        case '3':
            print_Schedule(up, 3);
            break;
        case '4':
            print_Schedule(up, 4);
            break;
        case '5':
            print_Schedule(up, 5);
            break;
        case 'b':
            student_Tab();
            break;
        case 'B':
            student_Tab();
            break;
    }
}

//TODO finish this
void Cli::list_Students() {
    system("clear");

    cout << "////////////   List Students   ////////////"
         << "\n"
         << "List by:"
         << "\n"
         << "[1] - Alphabetical Order"
         << "\n"
         << "[2] - UP Number"
         << "\n"
         << "[3] - Class"
         << "\n"
         << "[4] - "
         << "\n"
         << "[5] - Friday"
         << "\n"
         << "[B]- Go to previous menu"
         << "\n"
         << "[Q] - Quit tool"
         << "\n";

    vector<char> options = {'1','2','3', '4', '5','b','B'};
    char option = manage_Input(options, true);

    switch (option) {
        case '1':
            list_Students_alpha();
            break;
        case '2':
            list_Students_UP();
            break;
        case '3':

            break;
        case '4':
            break;

        case '5':

            break;
        case 'b':
            student_Tab();
            break;
        case 'B':
            student_Tab();
            break;
    }
}

void Cli::permute_Between_Students(){
    system("clear");

    int studentUp1=0, studentUp2=0;
    cout << "////////////   Permute two Students   ////////////"
         << "\n"
         << "Choose the first Student (up): ";
    cin >> studentUp1;

    cout << "\nChoose the second Student (up): ";
    cin >> studentUp2;
    cout << "\n";

    if(permute_Between_Students(studentUp1, studentUp2)){
        cout << "Student up" << studentUp1 << " changed classes with Student up" << studentUp2 << endl;
    }else{
        cout << "Permute was not possible" << endl;
    }
}

//TODO
bool Cli::permute_Between_Students(int student1, int student2) {}

void Cli::permute_One_Student(){
    system("clear");

    int studentUp1;
    string classCode;
    cout << "////////////   Permute one Student   ////////////"
         << "\n"
         << "Choose Student (up): ";
    cin  >> studentUp1;
    cout << "\n"
         << "Choose Class to move student (1LEIC01 - 3LEIC15): ";
    cin  >> classCode;
    cout << "\n";

    if(permute_One_Student(studentUp1, classCode)){
        cout << "Student up" << studentUp1 << " was changed to class " << classCode << endl;
    }else{
        cout << "Permutation was not possible due to inbalance between classes";
    }

}

//TODO
bool Cli::permute_One_Student(int studentUp1, string classCodeToChangeTo) {}

//TODO
void Cli::print_Schedule(int up, int day) const {}

//TODO finish this
void Cli::list_Students_alpha(){
    system("clear");

    cout << "////////////   List Students Alphabetically   ////////////"
         << "\n"
         << "[1] - Ascending Order"
         << "\n"
         << "[2] - Descending Order"
         << "\n";

    vector<char> options = {'1','2'};
    char option = manage_Input(options, true);

    switch (option) {
        case '1':
            //for loop to print in ascending order
            break;
        case '2':
            //for loop to print in descending order
            break;
    }
}

//TODO finish this
void Cli::list_Students_UP(){
    system("clear");

    cout << "////////////   List Students By UP   ////////////"
         << "\n"
         << "[1] - Ascending Order"
         << "\n"
         << "[2] - Descending Order"
         << "\n";

    vector<char> options = {'1','2'};
    char option = manage_Input(options, true);

    switch (option) {
        case '1':
            //for loop to print in ascending order
            break;
        case '2':
            //for loop to print in descending order
            break;
    }
}