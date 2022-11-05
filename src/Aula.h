#ifndef AULA_H
#define AULA_H

#include "Date.h"

class Aula{
private:
    std::string _classCode;
    Date _date;
    std::string _type;

public:
    Aula();
    Aula(const std::string& classCode);
    Aula(const std::string& classCode, const Date& date, const std::string& type);
    void set_ClassCode(const std::string& classCode);
    void set_ClassDate(const Date& date);
    void set_Type(const std::string& type);
    std::string get_ClassCode();
    Date get_ClassDate();
    std::string get_Type();
    bool operator==(const Aula& aula) const;
    bool operator<(const Aula& aula) const;
};

#endif