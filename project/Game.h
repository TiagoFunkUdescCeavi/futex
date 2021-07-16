#ifndef GAME_H
#define GAME_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Goal.h"

class Game {
public:
    
    Game( string home, string visitor, int qty_home_goals, int qty_visitor_goals );
    
    string get_home();
    string get_visitor();
    int get_qty_home_goals();
    int get_qty_visitor_goals();

    void set_home_goal( Goal * goal );
    void set_visitor_goal( Goal * goal );
    
    bool operator==( Game* g );

    string to_string();
private:
    string home;
    string visitor;
    
    int qty_home_goals;
    int qty_visitor_goals;

    vector< Goal * > home_goals;
    vector< Goal * > visitor_goals;

};

#endif

