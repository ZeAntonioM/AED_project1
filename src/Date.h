#ifndef DATE_H
#define DATE_H

#include <string>
#include <map>
#include <math.h>

struct Time
{
    float hours;
    float minutes;
};

static std::map<std::string, int> Weekdays = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};

class Date
{
private:
    int _day{};
    std::string _stringDay;

    Time _startingTime = {0, 0};
    Time _endingTime = {0, 0};

public:
    // Default constructor
    Date();
    // Date construtor
    Date(const std::string &day, const float &startingTime, const float &duration);

    // Setters
    // Sets starting time
    void set_StartingTime(const Time &startingTime);

    // Sets starting time
    void set_StartingTime(const float &startingTime);

    // Sets ending time
    void set_EndingTime(const Time &endingTime);

    // Sets ending time
    void set_EndingTime(const float &endingTime);

    // Sets day
    void set_Day(const int &day);

    // Sets day
    void set_Day(const std::string &day);

    // Getters
    // Returns starting time in Time
    Time get_StartingTime_T() const;

    // Returns starting time in float
    float get_StartingTime_f() const;

    // Returns ending time in Time
    Time get_EndingTime_T() const;

    // Returns ending time in float
    float get_EndingTime_f() const;

    // Returns day in string
    std::string get_Day_s() const;

    // Returns day in int
    int get_Day_i() const;

    bool collides(const Date &d2) const;

    bool operator==(const Date &date) const;
};

#endif
