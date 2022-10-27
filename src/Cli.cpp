#include <iostream>
#include <map>
#include <vector>
#include "Cli.h"

using namespace std;

char Cli::manage_Input(const vector<char> &options_vector, bool allow_back)
{
     char option;

     while (true)
     {
          cout << "\n"
               << "Option: ";
          cin >> option;
          bool check_to_break = false;

          if (option == 'Q' || option == 'q'){system("clear"); check_To_Brake = true; break;} // quit the tool

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

    check_To_Brake = false;
    while(!check_To_Brake) {
        char option;

        system("clear");

        //////////////   Main menu  //////////////

        cout << "\n--- Select one of the following options: ---\n"
             << "\n"
             << "------------ Lists and searches ------------\n"
             << "\n"
             << "[1] - Search for student or student information"
             << "\n"
             << "[2] - Search for UC or UC information"
             << "\n"
             << "[3] - Search for Class or Class information"
             << "\n\n"
             << "------------------ Tools ------------------\n"
             << "\n"
             << "[4] - Class permute"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> v = {'1', '2', '3', '4'};
        option = manage_Input(v, false);

        switch (option) {
            case '1':
                student_Tab();
                break;
            case '2':
                uc_Tab();
                break;
            case '3':
                class_Tab();
                break;
            case '4':
                class_Permute_Tab();
                break;
        }
    }


}

//TODO implementar a list_Students() e get_Student_Schedule()
void Cli::student_Tab()
{
    check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear"); // limpar o terminal ao invocar o comando da shell "clear"
        cout << "\n----------- Students Information -----------\n"
             << "\n"
             << "--- Select one of the following options: ---\n"
             << "\n"
             << "[1] - Get schedule"
             << "\n"
             << "[2] - List Students"
             << "\n"
             << "[B] - Go back to main menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
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
}

//TODO
void Cli::uc_Tab() {
    check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");


        cout << "\n------------- Unidades Curriculares -------------\n"
             << "\n"
             << "--- Select one of the following options: ---\n"
             << "\n"
             << "[1] - List UCs"
             << "\n"
             << "[2] - Get UC Lectures"
             << "\n"
             << "[3] - Number of Students in given UC"
             << "\n"
             << "[B] - Go back to main menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2','3'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                list_UCs();
                break;
            case '2':
                get_UC_Lectures();
                break;
            case '3':
                number_Student_UC();
                break;
            case 'b':
                startup();
                break;
            case 'B':
                startup();
                break;
        }
    }
}

//TODO Dont know if this should even exist or not
void Cli::class_Tab() {

    check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");

        cout << "\n----------------- Classes ------------------\n"
             << "\n"
             << "--- Select one of the following options: ---\n"
             << "\n"
             << "[1] - List Classes"
             << "\n"
             << "[2] - Get Class Occupation"
             << "\n"
             << "[B] - Go back to main menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                list_Classes();
                break;
            case '2':
                get_Class_Occupation();
                break;
            case 'b':
                startup();
                break;
            case 'B':
                startup();
                break;
        }

    }
};

//TODO everything
void Cli::class_Permute_Tab(){
    check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");

        cout << "\n--------------- Class Permute --------------\n"
             << "\n"
             << "---------- Choose how to permute -----------\n"
             << "\n"
             << "[1] - Between two students"
             << "\n"
             << "[2] - One student only"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                permute_Between_Students();
                break;
            case '2':
                permute_One_Student();
                break;
            case 'b':
                startup();
                break;
            case 'B':
                startup();
                break;
        }
    }
}

//SUB MENUS

//TODO
void Cli::get_Student_Schedule() {

    check_To_Brake = false;
    while(!check_To_Brake) {
        string up;
        cout << "\nIntroduce the student's UP code (only the number): ";
        cin >> up;
        cout << "\n";
        system("clear");

        // função para verificar se o estudante existe

        // o plano é para substituir o up no printf pelo nome do estudante
        // mas ainda não os tenho ent vai ficar o up por agr

        cout << "\n----------- Student up" << up << " ------------\n"
             << "\n"
             << "-------------- Choose a day: ---------------\n"
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
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2', '3', '4', '5'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                print_Schedule(stoi(up), 1);
                break;
            case '2':
                print_Schedule(stoi(up), 2);
                break;
            case '3':
                print_Schedule(stoi(up), 3);
                break;
            case '4':
                print_Schedule(stoi(up), 4);
                break;
            case '5':
                print_Schedule(stoi(up), 5);
                break;
            case 'b':
                student_Tab();
                break;
            case 'B':
                student_Tab();
                break;
        }
    }
}

//TODO finish this
void Cli::list_Students() {
    check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");

        cout << "\n--------------- List Students --------------\n"
             << "\n"
             << "------------------ List by -----------------\n"
             << "\n"
             << "[1] - Alphabetical Order"
             << "\n"
             << "[2] - UP Number"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2', '3', '4', '5'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                list_Students_alpha();
                break;
            case '2':
                list_Students_UP();
                break;
            case 'b':
                student_Tab();
                break;
            case 'B':
                student_Tab();
                break;
        }
    }
}

//TODO finish this
void Cli::list_Students_alpha(){
    check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");

        cout << "\n------- List Students Alphabetically -------\n"
             << "\n"
             << "[1] - Ascending Order"
             << "\n"
             << "[2] - Descending Order"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                //TODO for loop to print in ascending order
                break;
            case '2':
                //TODO for loop to print in descending order
                break;
            case 'b':
                list_Students();
                break;
            case 'B':
                list_Students();
                break;
        }
    }
}

//TODO finish this
void Cli::list_Students_UP(){
    check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");

        cout << "\n------------ List Students By UP -----------\n"
             << "\n"
             << "[1] - Ascending Order"
             << "\n"
             << "[2] - Descending Order"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                //TODO for loop to print in ascending order
                break;
            case '2':
                //TODO for loop to print in descending order
                break;
            case 'b':
                list_Students();
                break;
            case 'B':
                list_Students();
                break;
        }
    }
}

//TODO
void Cli::print_Schedule(int up, int day) {
    static std::map<int, std::string> Weekdays = {{1, "Monday"}, { 2,"Tuesday"}, {3,"Wednesday"}, {4,"Thursday"}, {5,"Friday"}};

    system("clear");
    cout << "\n------ Student up" << up << " " << Weekdays.at(day) << "'s Schedule ------\n";
        //TODO print horario do estudante no dia x
}

//TODO
void Cli::list_UCs() {


    string year;

    cout << "\nIntroduce the academic year: ";
    cin >> year;
    system("clear");

    //TODO Mostrar a lista de ucs para o ano academico


}

//TODO
void Cli::get_UC_Lectures(){
    string classCode;

    cout << "\nIntroduce the Class Code (1LEIC01 - 3LEIC15): ";
    cin >> classCode;
    system("clear");

    //TODO Mostrar as aulas da uc dado a string de class code

}

//TODO
void Cli::number_Student_UC() {
    string ucCode;

    cout << "\nIntroduce the UC Code (L.EIC001- L.EIC025): ";
    cin >> ucCode;
    system("clear");

    //Mostrar o numero de students incritos nessa UC

}

//TODO
void Cli::list_Classes(){

    check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");

        cout << "\n--------------- List Classes ---------------\n"
             << "\n"
             << "------------------- List -------------------\n"
             << "\n"
             << "[1] - All"
             << "\n"
             << "[2] - By UC"
             << "\n"
             << "[B] - Go to previous menu"
             << "\n"
             << "[Q] - Quit tool"
             << "\n";

        vector<char> options = {'1', '2'};
        char option = manage_Input(options, true);

        switch (option) {
            case '1':
                list_All_UCs();
                break;
            case '2':
                list_By_UC();
                break;
            case 'b':
                class_Tab();
                break;
            case 'B':
                class_Tab();
                break;
        }

    }

}
//TODO
void Cli::list_All_UCs(){
    //TODO listar todas as turmas
}

//TODO
void Cli::list_By_UC(){
    string ucCode;

    cout << "\nIntroduce the UC Code (L.EIC001- L.EIC025): ";
    cin >> ucCode;
    system("clear");

    //TODO listar as turmas por UC dada
}

//TODO
void Cli::get_Class_Occupation() {
    string ucCode;

    cout << "\nIntroduce the UC Code (L.EIC001- L.EIC025): ";
    cin >> ucCode;
    system("clear");

    //TODO mostrar quantidade de alunos inscritos na uc dada
}

void Cli::permute_Between_Students(){
    system("clear");

    int studentUp1=0, studentUp2=0;
    cout << "\n----------- Permute two Students -----------\n"
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
bool Cli::permute_Between_Students(int student1, int student2) {return 1;}

void Cli::permute_One_Student(){
    system("clear");

    int studentUp1;
    string classCode;
    cout << "\n----------- Permute one Student ------------\n"
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
bool Cli::permute_One_Student(int studentUp1, string classCodeToChangeTo) {return 1;}