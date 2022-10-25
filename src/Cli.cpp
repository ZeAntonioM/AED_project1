#include <iostream>
#include <vector>
#include "Cli.h"

using namespace std;

char Cli::manage_Input(vector<char> options_vector, bool allow_back) const
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

void Cli::startup() const
{
     char option;
     system("clear"); // limpar o terminal ao invocar o comando da shell "clear"
     cout << "//////////////   Schedule Tool   //////////////"
          << "\n"
          << "\n"
          << "Select one of the following options:"
          << "\n"
          << "\n"
          << "[1] - Search for student or student information" //student_tab()
          << "\n"
          << "[2] - Search for UC or UC information"   //uc_tab()
          << "\n"
          << "[3] - Class permute"                //class_permute_tab()
          << "\n"
          << "[4] - General listings"        //general_listings_tab()
          << "\n"
          << "[Q] - Quit tool"          
          << "\n";

     
     vector<char> v = {'1','2','3','4'};
     option = manage_Input(v, false);

     switch (option)
     {
     case '1':
          student_Tab();
          break;

     case '2':
          uc_Tab();
          break;

     case '3':
          //class_permute_tab();
          break;
     
     case '4':
          General_Listings_Tab();
          break;
     }
     
}
void Cli::student_Tab() const
{
     string up;

     cout << "\n" << "Introduce the student's UP code (only the number):     ";
     cin >> up;

     // função para verificar se o estudante existe

     // o plano é para substituir o up no printf pelo nome do estudante
     // mas ainda não os tenho ent vai ficar o up por agr

     system("clear"); // limpar o terminal ao invocar o comando da shell "clear"
     cout << "////////////   Student up" << up <<  "     ////////////"
          << "\n"
          << "\n"
          << "Select one of the following options:"
          << "\n"
          << "\n"
          << "[1] - Get schedule"            //get_StudentSchedule
          << "\n"
          << "[2] - Get class for each UC"   //get_ClassPerUC
          << "\n"
          << "[B] - Go back to main menu"    
          << "\n"
          << "[Q] - Quit tool"
          << "\n";

     vector<char> options = {'1','2'};
     char option = manage_Input(options, true);
     cout << option;
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
          << "\n"
          << "[1] - Get UC information"
          << "\n"
          << "[2] - Get UC Lectures"
          << "\n"
          << "[B] - Go back to main menu"
          << "\n"
          << "[Q] - Quit tool"
          << "\n";
}

void Cli::General_Listings_Tab() const{
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
          << "[3] - UC Vacancies"
          << "\n"
          << "[B] - Go back to main menu"
          << "\n"
          << "[Q] - Quit tool"
          << "\n";

}