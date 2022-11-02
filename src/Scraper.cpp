#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Scraper.h"

using namespace std;


Scraper::Scraper(){}

Scraper::~Scraper(){}

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

bool reSort(Student s1, Student s2){
    return (s1.get_Name() <= s2.get_Name());
}

vector<Student> Scraper::build_StudentsName(){
    for (auto i: _student_Set){
        _student_VectorName.push_back(i);
    }

    sort(_student_VectorName.begin(), _student_VectorName.end(), reSort);
    return _student_VectorName;
}

void Scraper::update_StudentCount(){
    vector<tuple<string,string,int>> aux_vec;
    bool check = true;
    for (auto s: _student_Set){
        for (auto t: s.get_Schedule()){
            check = true;

            for(auto &tup: aux_vec){
                if(get<0>(tup) == get<0>(t).get_Code() && get<1>(tup) == (get<1>(t).get_ClassCode()+get<1>(t).get_Type())){
                    get<2>(tup) = get<2>(tup) + 1; check = false;
                }
            }
            
            if (check){
                aux_vec.push_back(make_tuple(get<0>(t).get_Code(), get<1>(t).get_ClassCode() + get<1>(t).get_Type(), 1));
            }
        }
    }

    for (auto t: aux_vec){
        _student_Count.insert(t);
    }
}

set<Student>& Scraper::get_StudentSet(){
    return _student_Set;
}

set<Uc> Scraper::get_UcSet(){
    return _uc_Set;
}