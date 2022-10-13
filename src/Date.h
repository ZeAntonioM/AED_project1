#ifndef DATE_H
#define DATE_H

#include <string>
#include <map>
#include <math.h>

struct Time{
    float hours;
    float minutes;
};

static std::map<std::string, int> Weekdays = {{"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2}, {"Thrusday", 3}, {"Friday", 4}};

class Date{
private:    
    int _day;
    std::string _stringDay;

    Time _startingTime = {0,0};
    Time _endingTime = {0,0};

public:
    //Default constructor
    Date();
    //Date construtor
    Date(std::string day, float startingTime, float duration);


    //Setters
    //Sets starting time
    void setStartingTime(Time startingTime);

    //Sets starting time
    void setStartingTime(float startingTime);

    //Sets ending time
    void setEndingTime(Time endingTime);

    //Sets ending time
    void setEndingTime(float endingTime);

    //Sets day
    void setDay(int day);

    //Sets day
    void setDay(std::string day);

    //Getters
    //Returns starting time in Time 
    Time getStartingTime_T();

    //Returns starting time in float
    float getStartingTime_f();

    //Returns ending time in Time 
    Time getEndingTime_T();

    //Returns ending time in float
    float getEndingTime_f();

    //Returns day in string
    std::string getDay_s();

    //Returns day in int
    int getDay_i();
};

#endif
