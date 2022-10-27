#include "Student.h"

    /**
     * Contrutor da Classe Student: Recebe como atibutos uma string relativa ao nome e outra relativa ao up do estudante. 
     * Em caso de ser criado um estudante sem atributos, a esses parametros é atribuido o valor NULL.
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
     * Recebe como atributo uma string que é atribuída ao nome do estudante.
    */
    void Student::set_Name(string name_) { name = name_;}

    /**
     * Recebe como atributo uma string que é atribuida como up do estudante.
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
     * Recebe uma Unidade Curricular e uma Aula como atributos, os quais são passados como tuplo de modo a serem adicionados ao "Horário" do estudante.
    */
    void Student::add_UcClass(Uc cadeira, Aula turma){
        tuple<Uc,Aula> novaucturma (cadeira, turma);
        schedule.push_back(novaucturma);
    }

    /**
     * Percorre as turmas em que o estudante está inscrito e remove a turma passada como atributo se esta for encontrada.
    */
    void Student::remove_UcClass(Uc cadeira, Aula turma){
        tuple<Uc, Aula> UCTurmRemove (cadeira, turma);
        auto posi = schedule.begin();
        for (long unsigned int i = 0; i < schedule.size(); i++) {
            if (schedule[i] == UCTurmRemove) { schedule.erase(posi); break; }
            posi++;
        }
    }




