#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <unistd.h>
#include "Cli.h"

using namespace std;

//TODO anytime you need to wait for user input to continue use function wait_for_input()

//TODO verificar as funcoes para ver se ha casos em que da para fazer binary search para ser mais eficiente

/**
 * Função chamada sempre durante cada função de interface. É usada para gerir os inputs do utilizador e também para controlar o buffer. 
 * Retorna a opção do utilizador.
*/
char Cli::manage_Input(const vector<char> &options_vector, bool allow_back)
{
    char option;

    while (true)
    {

        cout << "\n"
             << "Option: ";
        cin >> option;
        bool check_to_break = false;

        if (option == 'Q' || option == 'q'){system("clear");
            check_quit = true;
            processQueue();
            break;
        } // quit the tool

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

/**
 * Interface inicial do programa.
 * Invoca a função manageInput de modo a obter o input do utilizador e leva o mesmo a uma nova interface dependendo do resultado.
*/
void Cli::startup()
{

    bool check_To_Brake = false;
    while(!check_To_Brake) {
        char option;

        system("clear");
        if(check_quit) break;

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

/**
 * Menu referente a estudantes.
 * Invoca a função manageInput de modo a obter o input do utilizador e leva o mesmo a uma nova interface dependendo do resultado.
 */
void Cli::student_Tab()
{
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear"); // limpar o terminal ao invocar o comando da shell "clear"
        if(check_quit) break;
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
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}

/**
 * Menu referente a Unidades Curriculares.
 * Invoca a função manageInput de modo a obter o input do utilizador e leva o mesmo a uma nova interface dependendo do resultado.
 */
void Cli::uc_Tab() {
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;


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
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}

/**
 * Menu referente a turmas. 
 * Invoca a função manageInput de modo a obter o input do utilizador e leva o mesmo a uma nova interface dependendo do resultado.
 */
void Cli::class_Tab() {

    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

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
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }

    }
};

/**
 * Menu referente a permuta de estudantes. 
 * Invoca a função manageInput de modo a obter o input do utilizador e leva o mesmo a uma nova interface dependendo do resultado.
 */
void Cli::class_Permute_Tab(){
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

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
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}

//SUB MENUS
/**
 * Menu referente aos horários dos estudantes. 
 * Invoca a função manageInput de modo a obter o input do utilizador, que será referente ao dia da semana escolhido pelo mesmo. 
 * Chama a funcao print_Schedule() com argumentos conforme as escolhas do utilizador
 */
void Cli::get_Student_Schedule() {

    bool check_To_Brake = false;
    bool check_ignore_up = false;
    string up;
    Student student;
    while(!check_To_Brake) {
        if(check_quit) break;
        if(!check_ignore_up){
            cout << "\nIntroduce the student's UP code (only the number): ";
            cin >> up;
            cout << "\n";

            Student s("nothing", up);
            auto search = _setStudent.find(s);

            if (search == _setStudent.end()){cout << "Student not found"; continue;}
            student = *search;
        }
        system("clear");
        check_ignore_up = true;

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
                print_Schedule(student, 1);
                break;
            case '2':
                print_Schedule(student, 2);
                break;
            case '3':
                print_Schedule(student, 3);
                break;
            case '4':
                print_Schedule(student, 4);
                break;
            case '5':
                print_Schedule(student, 5);
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}

/**
 * Menu referente a listagens orenada de estudantes.
 * Invoca a função manageInput de modo a obter o input do utilizador e leva o mesmo a uma nova interface dependendo do resultado.
 */
void Cli::list_Students() {
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

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
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}

/**
 * Invoca a função manageInput de modo a obter o input do utilizador e lista os estudantes por ordem alfabética, crescente ou descrecente dependendo do resultado.
 */
void Cli::list_Students_alpha(){
    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

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
                for (auto student: _vectorStudent){
                    cout <<"\n" << student.get_Up() << ": " << student.get_Name();
                }
                wait_for_input();
                break;
            case '2':
                for(auto rit = _vectorStudent.rbegin(); rit != _vectorStudent.rend(); rit++){
                    cout << "\n" << (*rit).get_Up() << ": " << (*rit).get_Name();
                }

                wait_for_input();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}

/**
 * Invoca a função manageInput de modo a obter o input do utilizador e lista os estudantes por ordem de número mecanografico, crescente ou descrecente dependendo do resultado.
 */
void Cli::list_Students_UP(){

    //Reserve iterator used to list in Descending Order
    set<Student>::reverse_iterator rit;

    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

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

                for(const auto& student : _setStudent){
                    cout <<"\n" << student.get_Up() << ": " << student.get_Name();
                }
                wait_for_input();
                break;
            case '2':

                for(rit = _setStudent.rbegin(); rit != _setStudent.rend(); rit++){
                    cout << "\n" << (*rit).get_Up() << ": " << (*rit).get_Name();
                }

                wait_for_input();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }
    }
}

/**
 * Apresenta o horário de certo dia de um dado estudante escolhido pelo utilizador. 
 */
void Cli::print_Schedule(Student student, int day) {
    static std::map<int, std::string> Weekdays = {{1, "Monday"}, { 2,"Tuesday"}, {3,"Wednesday"}, {4,"Thursday"}, {5,"Friday"}};
    system("clear");

    cout << "\n------ Student up" << student.get_Up() << ": " << Weekdays.at(day) << "'s Schedule ------\n\n";

    for (auto t : student.get_Schedule()){
        if (get<1>(t).get_ClassDate().get_Day_s() == Weekdays.at(day)){
        cout << "\n" << "UC: " << get<0>(t).get_Code() << "\n"
             << "Class: " << get<1>(t).get_ClassCode() << " (" << get<1>(t).get_Type() << ") "  << "\n"
             << get<1>(t).get_ClassDate().get_StartingTime_T().hours <<":"<< setw(2) << setfill('0') << get<1>(t).get_ClassDate().get_StartingTime_T().minutes << " -> " 
             << get<1>(t).get_ClassDate().get_EndingTime_T().hours << ":" << setw(2) << setfill('0') << get<1>(t).get_ClassDate().get_EndingTime_T().minutes << endl ;
        }
    }
    cout << "\n";


    wait_for_input();
    system("clear");
}


/**
 * Lista todas as Unidades curriculares num determinado ano escolhido pelo input do utilizador. 
*/
void Cli::list_UCs() {

    string year;

    cout << "\nIntroduce the academic year (1-3): ";
    cin >> year;
    system("clear");

    //pode ser convertido para regex para aceitar 1,2,3 ou 2019,2020,2021
    if(year=="1" or year=="2" or year=="3") {

        for (auto uc: _setUc) {

            string UcCode = uc.get_Code();

            if ((UcCode[6] - '0') == (stoi(year) - 1)) {
                cout << "\n" << UcCode;
            }
        }
    }
    else{
        cout << "Invalid Input, please try again\n";
    }
    cin.ignore(INT16_MAX, '\n');
    wait_for_input();
    system("clear");

}

/**
 * Pede ao utilizador a UC cujas aulas o mesmo quer verificar. 
 * Após o utilizador introduzir um código de UC válido, a função lista as aulas.
*/
void Cli::get_UC_Lectures(){
    string ucCode;

    cout << "\nIntroduce the UC Code (L.EIC001 - L.EIC025): ";
    cin >> ucCode;
    system("clear");

    //Usei regex para facilitar a minha vida, podia ter feito melhor para aceitar strings
    //do genero '001' ou '025' mas depois ia ter que alterar a string de input para o find conseguir
    //encontrar um match
    if(std::regex_match(ucCode, std::regex("(L.EIC0)[012][12345]"))) {

        auto UcCode = _setUc.find(Uc(ucCode));
        if (UcCode == _setUc.end()) {
            cout << "The entered UC was not found, please try again" << endl;
        }
        vector<Aula> lectures = (*UcCode).get_Turmas();
        int count = 1;
        cout << "\n ------------------------------------ Lectures of UC " << ucCode << " ------------------------------------\n";
        for (Aula lecture: lectures) {
            cout << "\nLecture number " << count << " on " << lecture.get_ClassDate().get_Day_s() <<  ":\n"
                 << lecture.get_ClassDate().get_StartingTime_T().hours << ":" << setw(2) << setfill('0') << lecture.get_ClassDate().get_StartingTime_T().minutes << " -> "
                 << lecture.get_ClassDate().get_EndingTime_T().hours << ":" << setw(2) << setfill('0') << lecture.get_ClassDate().get_EndingTime_T().minutes << "\n";
            count++;
        }
    }else{
        cout << "Invalid Input, please try again\n";
    }
    cin.ignore(INT16_MAX, '\n');
    wait_for_input();
    system("clear");

}


/**
 * Pede ao utilizador para introduzir o código da UC cujo utilizador pretende verificar a quantidade de alunos. 
 * Após o utilizador introduzir uma input válido, a função imprime a quantidade de alunos que a UC tem.
*/
void Cli::number_Student_UC() {
    string ucCode;

    cout << "\nIntroduce the UC Code (L.EIC001 - L.EIC025): ";
    cin >> ucCode;
    system("clear");

    if(std::regex_match(ucCode, std::regex("(L.EIC0)[012][12345]"))) {
        int studentCount = 0;
        
        for (auto t: _studentCount){
            if (get<0>(t) == ucCode && get<1>(t).length() == 8){
                studentCount += get<2>(t);
            }
        }
        
        cout << "\nUC " << ucCode << " has " << studentCount << " students enrolled"<< endl;
    }else{
        cout << "Invalid Input, please try again\n";
    }
    cin.ignore(INT16_MAX, '\n');
    wait_for_input();
    system("clear");


}

/**
 * Menu referente à seleção do tipo de listagem de turmas.
 * Invoca a função manageInput de modo a obter o input do utilizador e leva o mesmo a uma nova interface dependendo do resultado.
*/
void Cli::list_Classes(){

    bool check_To_Brake = false;
    while(!check_To_Brake) {
        system("clear");
        if(check_quit) break;

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
                list_All_Classes();
                break;
            case '2':
                list_By_UC();
                break;
            case 'b':
                check_To_Brake = true;
                break;
            case 'B':
                check_To_Brake = true;
                break;
        }

    }

}


/**
 * Lista todas as turmas em todas as Unidades curriculares.
*/
void Cli::list_All_Classes() {

    set<Aula> tmpTurmas;

    for(auto uc : _setUc){
        auto turmas = uc.get_Turmas();
        for(auto turma : turmas){
            tmpTurmas.insert(turma);
        }
    }

    for(auto turma : tmpTurmas){
        cout << "\n" << turma.get_ClassCode();
    }

    wait_for_input();
    system("clear");
}

/**
 * Pede ao utilizador para introduzir o código da UC cujo utilizador pretende listar as várias turmas existentes.
 * Após um input válido, a função lista o código da turma e o tipo de aulas que a turma tem.
*/
void Cli::list_By_UC(){

    string ucCode;
    cout << "\nIntroduce the UC Code (L.EIC001- L.EIC025): ";
    cin >> ucCode;
    system("clear");

    if(std::regex_match(ucCode, std::regex("(L.EIC0)[012][12345]"))) {
        auto uc = _setUc.find(Uc(ucCode));

        auto turmas = uc->get_Turmas();
        for(auto turma : turmas){
            if(turma.get_Type() == "T")
                cout << "\n" << turma.get_ClassCode();
        }

    }else{
        cout << "Invalid Input, please try again\n";
    }

    cin.ignore(INT16_MAX, '\n');
    wait_for_input();
    system("clear");
}

/**
 * Pede ao utilizador para introduzir o código da turma cujo utilizador pretende verificar a quantidade de alunos. 
 * Após um input válido a função lista a quantidade de alunos da turma para aulas T,TP e PL.
*/
void Cli::get_Class_Occupation() {

    string classCode;
    cout << "\nIntroduce the Class Code (1LEIC01 - 3LEIC15): ";
    cin >> classCode;
    system("clear");

    if(std::regex_match(classCode, std::regex("[123](LEIC)[01][12345]"))) {
        for(auto t: _studentCount) {
            if(get<1>(t).substr(0, 7) == classCode){
                cout <<"\nClass " << get<1>(t) << " in UC " << get<0>(t) << " has " << get<2>(t) << " students enrolled";
            }
        }
    }else{
        cout << "Invalid Input, please try again\n";
    }

    cin.ignore(INT16_MAX, '\n');
    wait_for_input();
    system("clear");
}

/**
 * Interface para a troca de turmas entre dois estudantes.
 * Pede o up dos dois estudantes e a Unidade Curricular a que os mesmos querem trocar.
 * Se a Unidade Curricular se verificar válida, entao chama a função permute_Between_Students(studentUp1, studentUp2, ucCode)
*/
void Cli::permute_Between_Students(){
    system("clear");

    string studentUp1, studentUp2, ucCode;
    cout << "\n----------- Permute two Students -----------\n"
         << "\n"
         << "Choose the first Student (up): ";
    cin >> studentUp1;

    cout << "\nChoose the second Student (up): ";
    cin >> studentUp2;
    cout << "\n";

    cout << "Choose UC to swap students (L.EIC001 - L.EIC025): ";
    cin >> ucCode;
    cout << "\n";

    if(std::regex_match(ucCode, std::regex("(L.EIC0)[012][12345]"))) {
        if (permute_Between_Students(studentUp1, studentUp2, ucCode)) {
            cout << "Student up" << studentUp1 << " changed UC " << ucCode << " classes with Student up" << studentUp2 << endl;
        } else {
            cout << "Permute was not possible" << endl;
        }
    } else{
        cout << "Invalid Input, please try again\n";
    }
    cin.ignore(INT16_MAX, '\n');
    wait_for_input();
    system("clear");

}


/**
 * Troca as turmas de dois estudantes, numa mesma Uc.
 * Após verificar se os números up estão corretos e se for possível realizar a troca, então a mesma é colocada em uma queue.
*/
bool Cli::permute_Between_Students(const string& studentUp1, const string& studentUp2, const string& ucToSwap) {

    vector<tuple<Uc, Aula>> tmpSchedule1, tmpSchedule2;

    auto student1it = _setStudent.find(Student("",studentUp1));
    if(student1it != _setStudent.end()){
        tmpSchedule1 = (*student1it).get_Schedule();
        bool ucFound = false;
        for(auto slot : tmpSchedule1){
            if(get<0>(slot)==ucToSwap){
                ucFound=true;
                break;
            }
        }

        if(!ucFound) {
            cout << "\nStudent up" << studentUp1 << " does not have UC " << ucToSwap << " ,please try again";
            return false;
        }

    } else{
        cout << "\nStudent up" << studentUp1 << " was not found, please try again";
        return false;
    }

    auto student2it = _setStudent.find(Student("",studentUp2));
    if(student2it != _setStudent.end()){
        tmpSchedule2 = (*student2it).get_Schedule();
        bool ucFound = false;
        for(auto slot : tmpSchedule2){
            if(get<0>(slot)==ucToSwap){
                ucFound=true;
                break;
            }
        }

        if(!ucFound) {
            cout << "\nStudent up" << studentUp2 << " does not have UC " << ucToSwap << " ,please try again";
            return false;
        }

    } else{
        cout << "\nStudent up" << studentUp2 << " was not found, please try again";
        return false;
    }


    permuteQueue.push((*student1it).get_Up());
    permuteQueue.push((*student1it).get_Name());
    permuteQueue.push(ucToSwap);

    for(auto slot : tmpSchedule2){
        if(get<0>(slot) == ucToSwap) {
            permuteQueue.push(get<1>(slot).get_ClassCode());
            break;
        }
    }

    permuteQueue.push((*student2it).get_Up());
    permuteQueue.push((*student2it).get_Name());
    permuteQueue.push(ucToSwap);

    for(auto slot : tmpSchedule1){
        if(get<0>(slot)==ucToSwap){
            permuteQueue.push(get<1>(slot).get_ClassCode());
            break;
        }
    }

    return true;
}

/**
 * Interface para a mudança de turma de um estudante
 * Pede ao utilizador para introduzir o up do estudante, a Uc e a turma para que o mesmo quer mudar.
 * Apś verificar a validade da Uc e da turma, é chamada a função permute_One_Student(studentUp1, ucCode, classCode)
*/
void Cli::permute_One_Student(){
    system("clear");

    string studentUp1;
    string classCode;
    string ucCode;
    cout << "\n----------- Permute one Student ------------\n"
         << "\n"
         << "Introduce Student (up): ";
    cin  >> studentUp1;
    cout << "\n"
         << "Introduce desired UC (L.EIC001 - L.EIC025): ";
    cin >> ucCode;
    cout << "\n"
         << "Introduce the class you wish to permute to (1LEIC01 - 3LEIC15): ";
    cin  >> classCode;
    cout << "\n";

    if(!std::regex_match(ucCode, std::regex("(L.EIC0)[012][12345]")))
        cout << "Invalid UC input, please try again\n";
    else if(!std::regex_match(classCode, std::regex("[123](LEIC)[01][12345]")))
        cout << "Invalid Class code input, please try again \n";
    else{
        if(permute_One_Student(studentUp1, ucCode,  classCode)){
            cout << "Student up" << studentUp1 << " was changed to class " << classCode << endl;
        }else{
            cout << "Permutation was not possible, please try again";
        }
    }

    cin.ignore(INT16_MAX, '\n');
    wait_for_input();
    system("clear");
}

/*
 * Após um input válido em todas as informações, a função verifica se é possivel realizar a troca sem que sejam quebradas regras de equilibrio.
 * Se for possível realizar a troca, então a mesma é colocada em uma queue.
 */
bool Cli::permute_One_Student(string studentUp1, string ucCode, string classCodeToChangeTo) {

    auto s_search = _setStudent.find(Student("", studentUp1));
    int minimum = INT16_MAX;
    string current_class;
    bool check = true;
    bool check2 = false;
    Student stu = *s_search;

    if (s_search != _setStudent.end()){
        for (auto t: stu.get_Schedule()){
            if (get<0>(t).get_Code() == ucCode) current_class = get<1>(t).get_ClassCode();
        }
        for (auto &tup: _studentCount){
            if(get<0>(tup) == ucCode){
                check = false;
                minimum = min(minimum, get<2>(tup));
                if(get<1>(tup).substr(0,7) == classCodeToChangeTo){
                    if(get<2>(tup) < _cap && get<2>(tup) + 1 < minimum + 4 && !check2){
                        check2 = true;
                        permuteQueue.push(studentUp1);
                        permuteQueue.push(stu.get_Name());
                        permuteQueue.push(ucCode);
                        permuteQueue.push(classCodeToChangeTo);
                    }
                    else if(!check2) {cout << "Permute wasn't possible due to an imbalance between classes\n";wait_for_input(); return false;}
                }
            }
        }

        for (auto &tup: _studentCount){
            if (check2){
                if (get<0>(tup) == ucCode && get<1>(tup).substr(0,7) == current_class) get<2>(tup) -= 1;
            }
        }

        if (check){ cout << "UC wasn't found or the Class specified doesn't belog to the UC\n";wait_for_input(); return false;}
        return true;
    }
    else{cout << "Student wasn't found\n"; wait_for_input();}
    return false;
}
/**
 * Imprime "Press ENTER to continue...".
 * É geralmente chamada após uma função de listagem, de modo a que o utilizador possa decidir que já verificou os dados que pretende verificar.
*/
void Cli::wait_for_input(){

    do
    {
        cout << '\n' << "Press ENTER to continue...";
    } while (cin.get() != '\n');

}

/**
 * Processa os dados colocados na queue.
 * Produz um ficheiro .csv na pasta "output" com as permutas ja processadas.
 * Se o ficheiro já existir, adiciona as novas permutas a este mesmo.
 * É chamada só no fim do programa.
 */
void Cli::processQueue() {

    if(!permuteQueue.empty()){

        ofstream ProcessedPermutes;
        ProcessedPermutes.open("output/ProcessedPermutes.csv", ios::out | ios::app);//opens file to write

        int count=0;
        while(!permuteQueue.empty()){
            if(count==4){
                count=0;
                ProcessedPermutes << endl;
            }else if(count==3){
                ProcessedPermutes << permuteQueue.front();
                permuteQueue.pop();
                count++;

            } else{
                ProcessedPermutes << permuteQueue.front() << ',';
                permuteQueue.pop();
                count++;
            }
        }
        ProcessedPermutes << endl;
        ProcessedPermutes.close();
        cout << "\nPermute queue was processed\n";
    }
}
