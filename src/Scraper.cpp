#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "Scraper.h"

using namespace std;

/**
 * Default constructor da classe Scrapper.
 * Complexity: O(1).
*/
Scraper::Scraper(){}

/**
 * Destuctor da classe Scrapper.
 * Complexity: O(1).
*/
Scraper::~Scraper(){}

/**
 * Lê um ficheiro e passa todas as palavras separadas por virgulas para um vetor.
 * Complexity: O(n), sendo n o número de strings individuais (string entre duas vírgulas) presentes no ficheiro.
 * @param filename string referente ao nome do file que irá ser lido
 * @return vetor que contém todas as palavras do ficheiro.
*/
vector<string> Scraper::scrape_File(string filename){
    _columns = 0;
    ifstream file;
    file.open(filename);

    string line;
    getline(file,line);

    string word;
    stringstream s1(line);

    while (getline(s1,word,',')){
        _columns++;
    }

    vector<string> result;

    while (file.good()){

        getline(file, line);
        stringstream ss(line);

        while (getline(ss, word, ',')){
            result.push_back(word);
        }
    }

    return result;
}

/**
 * Itera o vetor das palavras do ficheiro students_classes.csv e cria estudantes adicionando os mesmos ao set deestudantes. 
 * Atribui também aos mesmos as aulas que estes têm, juntamente com o tipo da aula.
 * Complexity: O(n log(w) log(q)), sendo n o número de elementos no vetor que contém as strings lidas no ficheiro, w o número de estudantes já presentes no _student_Set, e q o número de UCs já presentes no _uc_Set.
 * @param vector vetor que contem as palavras recebidas do ficheiro students_classes
 * @return Set de estudantes
*/
set<Student> Scraper::build_Students(vector<string> vector){

    for (int i = 0; i < (int) vector.size(); i += _columns){
        Student student = Student(vector[1 + i], vector[0 + i]);

        auto uc_search = _uc_Set.find(Uc(vector[2+i]));
        auto student_search = _student_Set.find(Student(vector[1+i],vector[0+i]));

        Uc existing_uc = *uc_search;

        Aula turma_tp, turma_t, turma_pl;

        bool check_t = false, check_tp = false, check_pl = false;

        for (auto t: existing_uc.get_Turmas()){
            if (t.get_ClassCode() == vector[3+i]){
                if (t.get_Type() == "T"){ turma_t = t; check_t = true;}
                if (t.get_Type() == "TP"){ turma_tp = t; check_tp = true;}
                if (t.get_Type() == "PL"){ turma_pl = t; check_pl = true;}
            }
        }

        if (student_search == _student_Set.end()){ // se o student não existir
            if(check_t)student.add_UcClass(existing_uc, turma_t);
            if(check_tp)student.add_UcClass(existing_uc, turma_tp);
            if(check_pl)student.add_UcClass(existing_uc, turma_pl);
            _student_Set.insert(student);
        }
        else{  // sim é preciso criar um novo objeto com as mesmas cenas do anterior pq o * do std::set retorna um const  :(
            Student stu = *student_search; // passar do itr para objeto para usarmos as funçoes

            Student new_student = Student(stu.get_Name(), stu.get_Up());   // copiar para o novo os atributos do antigo
            new_student.set_Schedule(stu.get_Schedule());

            if(check_t)new_student.add_UcClass(existing_uc, turma_t);
            if(check_tp)new_student.add_UcClass(existing_uc, turma_tp);
            if(check_pl)new_student.add_UcClass(existing_uc, turma_pl);  //adicionar a nova turma lida

            _student_Set.erase(student_search);  // substituir o antigo pelo novo no set
            _student_Set.insert(new_student);
        }
    }
    return _student_Set;
}

/**
 * Cria um set com todas as unidades curriculares. Atibui às mesmas aulas e também datas a essas mesmas aulas.
 * Complexity: O(n log(w)), sendo n o número de elementos no vetor que contém as strings lidas no ficheiro, e w o número de UCs já presentes no _uc_Set.
 * @param vector vetor que contem as palavras do ficheiro classes
 * @return set de Unidades Curriculares existentes e suas respetivas aulas com horários.
*/
set<Uc> Scraper::build_Uc(vector<string> vector){

    for (int i = 0; i < (int)vector.size(); i += _columns){
        Uc uc = Uc(vector[1 + i]);
        Date date = Date(vector[2 + i], std::stof(vector[3+i]),std::stof(vector[4+i]));
        Aula aula = Aula(vector[0 + i], date, vector[5 + i]);

        auto search = _uc_Set.find(uc);

        if (search == _uc_Set.end()){
            uc.nova_Turma(aula);
            _uc_Set.insert(uc);
        }
        else{
            Uc u = *search;

            Uc new_uc = Uc(u.get_Code());
            new_uc.set_Turmas(u.get_Turmas());
            new_uc.nova_Turma(aula);

            _uc_Set.erase(search);
            _uc_Set.insert(new_uc);
        }

    }
    return _uc_Set;
}

/**
 * Ordena dois estudantes a partir dos seus nomes
 * Complexity: O(1), compara sempre dois estudantes.
 * @param s1 estudante que pretende ser menor
 * @param s2 estudante que pretende ser maior
 * @return se o estudante s1 é menor ou igual ao estudante s2 segundo o seu nome.
*/
bool reSort(Student s1, Student s2){
    return (s1.get_Name() <= s2.get_Name());
}

/**
 * Ordena os estudantes a partir da função reSort().
 * Complexity: O(n), sendo n o número de elementos do _student_Set.
 * @return vetor com os estudantes ordenados pelo seu nome
*/
vector<Student> Scraper::build_StudentsName(){
    for (auto i: _student_Set){
        _student_VectorName.push_back(i);
    }

    sort(_student_VectorName.begin(), _student_VectorName.end(), reSort);
    return _student_VectorName;
}

/**
 * Percorre cada estudante e aumenta a quuantidade de estudantes em cada aula.
 * Complexity: O(n*w*q), sendo n o número de elementos no _student_Set, w o número de elementos no vetor get_Schedule() de cada estudante, e q o número de elementos no vetor _student_Count.
*/
void Scraper::update_StudentCount(){
    bool check = true;
    for (auto s: _student_Set){
        for (auto t: s.get_Schedule()){
            check = true;

            for(auto &tup: _student_Count){
                if(get<0>(tup) == get<0>(t).get_Code() && get<1>(tup) == (get<1>(t).get_ClassCode()+get<1>(t).get_Type())){
                    get<2>(tup) = get<2>(tup) + 1; check = false;
                }
            }
            
            if (check){
                _student_Count.push_back(make_tuple(get<0>(t).get_Code(), get<1>(t).get_ClassCode() + get<1>(t).get_Type(), 1));
            }
        }
    }
}

void Scraper::read_Permutes(){
    auto vec = scrape_File("output/ProcessedPermutes.csv");

    for (int i = 0; i < (int)vec.size(); i += _columns){
        
        if (vec[i].substr(0,1) != "-"){
            auto s_search = _student_Set.find(Student(vec[i + 1], vec[i]));
            auto u_search = _uc_Set.find(Uc(vec[2+i]));

            Student stu = *s_search;
            Uc uc = *u_search;
            Aula turma_t, turma_tp, turma_pl;
            bool check1 = false, check2 = false, check3 = false;

            for (auto &a: uc.get_Turmas()){
                if (a.get_ClassCode() == vec[3 + i] && a.get_Type() == "T"){ turma_t = a; check1 = true;}
                if (a.get_ClassCode() == vec[3 + i] && a.get_Type() == "TP"){ turma_tp = a; check2 = true;}
                if (a.get_ClassCode() == vec[3 + i] && a.get_Type() == "PL"){ turma_pl = a; check3 = true;}
            }

            Student new_student = Student(vec[i + 1], vec[i]);
            new_student.set_Schedule(stu.get_Schedule());

            for (auto t: new_student.get_Schedule()){
                if (get<0>(t).get_Code() == vec[2+i]) new_student.remove_UcClass(get<0>(t), get<1>(t));
            }

            if (check1) new_student.add_UcClass(uc, turma_t);
            if (check2) new_student.add_UcClass(uc, turma_tp);
            if (check3) new_student.add_UcClass(uc, turma_pl);

            _student_Set.erase(s_search);
            _student_Set.insert(new_student);
        }
        else if(vec[i].substr(0,1) == "-"){
            auto s_search = _student_Set.find(Student(vec[i + 1], vec[i].substr(1,9)));
            auto u_search = _uc_Set.find(Uc(vec[2+i]));

            Student stu = *s_search;
            Uc uc = *u_search;
            Aula turma_t, turma_tp, turma_pl;
            bool check1 = false, check2 = false, check3 = false;

            for (auto &a: uc.get_Turmas()){
                if (a.get_ClassCode() == vec[3 + i] && a.get_Type() == "T"){ turma_t = a; check1 = true;}
                if (a.get_ClassCode() == vec[3 + i] && a.get_Type() == "TP"){ turma_tp = a; check2 = true;}
                if (a.get_ClassCode() == vec[3 + i] && a.get_Type() == "PL"){ turma_pl = a; check3 = true;}
            }

            Student new_student = Student(vec[i + 1], vec[i].substr(1,9));
            new_student.set_Schedule(stu.get_Schedule());
            if (check1) new_student.remove_UcClass(uc, turma_t);
            if (check2) new_student.remove_UcClass(uc, turma_tp);
            if (check3) new_student.remove_UcClass(uc, turma_pl);
            _student_Set.erase(s_search);
            _student_Set.insert(new_student);
        }
    }
}

/**
 * Getter do set de estudantes
 * Complexity: O(1)
 * @return set de estudantes
*/
set<Student>& Scraper::get_StudentSet(){
    return _student_Set;
}

/**
 * Getter do vetor de estudantes ordenados por nome
 * Complexity: O(1)
 * @return vetor com os estudantes ordenados pelo nome          
*/
vector<Student>& Scraper::get_StudentVectorName(){return _student_VectorName;}

/**
 * Getter do vetor que contém o número de estudantes por cada turma de cada UC
 * Complexity: O(1)
 * @return Quantidade de alunos
*/
vector<tuple<string, string, int>>& Scraper::get_StudentCount(){return _student_Count;}

/**
 * Getter do set de Unidades Curriculares.
 * Complexity: O(1)
 * @return set de Unidades Currículares
*/
set<Uc> Scraper::get_UcSet(){
    return _uc_Set;
}