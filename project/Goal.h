#ifndef GOAL_H
#define GOAL_H

#include <string>
using std::string;

class Goal{
    public:
        Goal( string player, string time, bool penalty, bool own_goal );
        bool operator<( Goal g );
        bool operator>( Goal g );
        string to_string();

    private:
        string player;
        string time;
        bool penalty;
        bool own_goal;
};

#endif