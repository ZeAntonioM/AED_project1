#include "Student.h"

/**
 * Contrutor da Classe Student: Recebe como atibutos uma string relativa ao nome e outra relativa ao up do estudante.
 * Em caso de ser criado um estudante sem atributos, a esses parametros é atribuido o valor NULL.
 * Complexity: O(1)
 * @param name string referente ao nome do estudante
 * @param up string referente ao up do estudante
*/
Student::Student(const string& name = NULL, const string& up = NULL) {
    _name = name;
    _up = up;
}

/**
 * Default Constuctor da classe Student.
 * Complexity: O(1)
*/
Student::Student() {};

/**
 * Destructor da Classe Student.
 * Complexity: O(1)
*/
Student::~Student() {};

/**
 * Recebe como atributo uma string que é atribuída ao nome do estudante.
 * Complexity: O(1)
 * @param name string referente ao nome a definir
*/
void Student::set_Name(const string& name) { _name = name; }

/**
 * Recebe como atributo uma string que é atribuida como up do estudante.
 * Complexity: O(1)
 * @param up string referente ao up a definir
*/
void Student::set_Up(const string& up) { _up = up; }

/**
 * Retorna o nome do estudante.
 * Complexity: O(1)
 * @return string com o nome do estudante
*/
string Student::get_Name() const { return _name; }

/**
 * Retorna o Up do estudante.
 * Complexity: O(1)
 * @return string com o numero up do estudante
*/
string Student::get_Up() const { return _up; }

/**
 * Recebe uma Unidade Curricular e uma Aula como atributos, os quais são passados como tuplo de modo a serem adicionados ao "Horário" do estudante.
 * Complexity: O(1)
 * @param cadeira objeto do tipo Uc referente à Unidade Curricular
 * @param turma objeto do tipo Aula referente à aula
*/
void Student::add_UcClass(const Uc& cadeira, const Aula& turma) {
    tuple<Uc, Aula> novaucturma(cadeira, turma);
    schedule.push_back(novaucturma);
}

/**
 * Percorre as turmas em que o estudante está inscrito e remove a turma passada como atributo se esta for encontrada.
 * Complexity: O(n)
 * @param cadeira objeto do tipo Uc referente à Unidade Curricular
 * @param turma objeto do tipo Aula referente à aula
*/
void Student::remove_UcClass(const Uc& cadeira, const Aula& turma) {
    tuple<Uc, Aula> UCTurmRemove(cadeira, turma);
    auto posi = schedule.begin();
    for (long unsigned int i = 0; i < schedule.size(); i++) {
        if (schedule[i] == UCTurmRemove) {
            schedule.erase(posi);
            break;
        }
        posi++;
    }
}

/**
 * Recebe um horário já existente e atribui esse horário ao estudante.
 * Complexity: O(1)
 * @param schedule vetor que contém tuplos compostos por um objeto do tipo Uc e outro do tipo Aula
*/
void Student::set_Schedule(const vector<tuple<Uc, Aula>>& schedule) {
    this->schedule = schedule;
}

/**
 * Retorna o horário atribuido ao estudante.
 * Complexity: O(1)
 * @return vetor de tuplos de Uc e Aula, i.e, o horário do estudante
*/
vector<tuple<Uc, Aula>> Student::get_Schedule() const {
    return schedule;
}

/**
 * Os estudantes são ordenados pelo seu up. Se o Up do estudante for menor que o do estudante s1, então o estudante é "menor".
 * Complexity: O(1)
 * @param s1 Objeto do tipo student que irá ser comparado
 * @return verdadeiro se o Up do estudante for menor que o do estudante s1
*/
bool Student::operator<(const Student& s1) const {
    return (_up < s1._up);
}


