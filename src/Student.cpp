#include "Student.h"

    /**
     * Contrutor da Classe Student: Recebe como atibutos uma string relativa ao nome e outra relativa ao up do estudante. 
     * Em caso de ser criado um estudante sem atributos, a esses parametros é atribuido o valor NULL.
    */
    Student::Student(string name = NULL, string up = NULL){
        _name = name;
        _up = up;
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
    void Student::set_Name(string name) { _name = name;}

    /**
     * Recebe como atributo uma string que é atribuida como up do estudante.
    */
    void Student::set_Up(string up) { _up = up;}

    /**
     * Retorna o nome do estudante.
    */
    string Student::get_Name() const { return _name;}

    /**
     * Retorna o Up do estudante.
    */
    string Student::get_Up() const { return _up;}  

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

    /**
     * Recebe um horário já existente e atribui esse horário ao estudante.
    */
    void Student::set_Schedule(vector<tuple<Uc,Aula>> schedule){
        this->schedule = schedule;
    }

    /**
     * Retorna o horário atribuido ao estudante.
    */
    vector<tuple<Uc,Aula>> Student::get_Schedule() const {
        return schedule;
    }

    /**
     * Os estudantes são ordenados pelo seu up. Se o Up do estudante for menor que o do estudante s1, então o estudante é "menor".
    */
    bool Student::operator< (Student s1) const{
        return (_up < s1._up);
    }


