#include "Student.h"

    /**
     * Contrutor da Classe Student: atribui o nome  e o up do estudante. Em caso de ser criado um estudante sem atributos, estes ficam a NULL.
    */
    Student::Student(string name_ = NULL, string up_ = NULL){
        name = name_;
        up = up_;
    }

    /**
     * Default Constuctor da classe Student.
    */
    Student::Student(){};

    /**
     * Destructor da Classe Student.
    */
    Student::~Student(){};

    /**
     * Atibui name_ ao nome do estudante.
    */
    void Student::set_Name(string name_) { name = name_;}

    /**
     * Atibui up_ ao número mecânografico(up) do estudante.
    */
    void Student::set_Up(string up_) { up = up_;}

    /**
     * Retorna o nome do estudante.
    */
    string Student::get_Name() { return name;}

    /**
     * Retorna o Up do estudante.
    */
    string Student::get_Up() { return up;}  

    /**
     * Adiciona uma turma ao horário do estudante. 
     * É adicionado um tuplo que contém tanto a UC como a turma a que o estudante está a ser atribuido.
    */
    void Student::add_UcClass(Uc cadeira, Aula turma){
        tuple<Uc,Aula> novaucturma (cadeira, turma);
        schedule.push_back(novaucturma);
    }

    /**
     * Remove uma turma do estudante.
     * Percorre as turmas em que o estudante está inscrito e remove a turma se esta for encontrada.
    */
    void Student::remove_UcClass(Uc cadeira, Aula turma){
        tuple<Uc, Aula> UCTurmRemove (cadeira, turma);
        auto posi = schedule.begin();
        for (long unsigned int i = 0; i < schedule.size(); i++) {
            if (schedule[i] == UCTurmRemove) { schedule.erase(posi); break; }
            posi++;
        }
    }




