#include <iostream>
#include <vector>
#include "Cli.h"

using namespace std;

char Cli::manage_input(vector<char> options_vector, bool allow_back) const
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

          if (check_to_break) break;  // uso o check to break para sair do while loop e não do for :)

          cout << "Invalid Input, please try again"
               << "\n";
          cin.ignore(INT16_MAX, '\n'); // limpar o buffer para não invalidar uma vez por cada caracter de input, caso escrevam mais q um
     }

     return option;
}

void Cli::startup() const
{
     char option;
     system("clear"); // limpar o terminal ao invocar o comando da shell "clear"
     cout << "//////////////   Schedule Tool   //////////////"
          << "\n"
          << " \n"
          << "Select one of the following options:"
          << "\n"
          << " \n"
          << "[1] - Search for student or student information"
          << "\n"
          << "[2] - Search for UC or UC information"
          << "\n"
          << "[3] - Class permute"
          << "\n"
          << "[Q] - Quit tool"
          << "\n";

     
     vector<char> v = {'1','2','3'};
     option = manage_input(v, false);

     switch (option)
     {
     case '1':
          student_tab();
          break;

     case '2':
          //  uc_tab();
          break;

     case '3':
          // class_permute_tab();
          break;
     }
     
}
void Cli::student_tab() const
{
     string up;
     system("clear"); // limpar o terminal ao invocar o comando da shell "clear"

     cout << "Introduce the student's UP code (only the number):     ";
     cin >> up;

     // função para verificar se o estudante existe

     // o plano é para substituir o up no printf pelo nome do estudante
     // mas ainda não os tenho ent vai ficar o up por agr

     cout << "////////////   Student up" << up <<  "////////////"
          << "\n"
          << " \n"
          << "Select one of the following options:"
          << "\n"
          << " \n"
          << "[1] - Get schedule"
          << "\n"
          << "[2] - Get class for each UC"
          << "\n"
          << "[B] - Go back to main menu"
          << "\n"
          << "[Q] - Quit tool"
          << "\n";

     vector<char> options = {'1','2'};
     char option = manage_input(options, true);
     cout << option;
}