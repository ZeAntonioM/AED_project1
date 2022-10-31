#ifndef DATE_H
#define DATE_H

#include <string>
#include <map>
#include <math.h>

struct Time{
    float hours;
    float minutes;
};

static std::map<std::string, int> Weekdays = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};

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
    void set_StartingTime(Time startingTime);

    //Sets starting time
    void set_StartingTime(float startingTime);

    //Sets ending time
    void set_EndingTime(Time endingTime);

    //Sets ending time
    void set_EndingTime(float endingTime);

    //Sets day
    void set_Day(int day);

    //Sets day
    void set_Day(std::string day);

    //Getters
    //Returns starting time in Time 
    Time get_StartingTime_T();

    //Returns starting time in float
    float get_StartingTime_f();

    //Returns ending time in Time 
    Time get_EndingTime_T();

    //Returns ending time in float
    float get_EndingTime_f();

    //Returns day in string
    std::string get_Day_s();

    //Returns day in int
    int get_Day_i();

    bool operator== (Date date) const;
};

#endif
