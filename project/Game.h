#ifndef GAME_H
#define GAME_H

#include <string>
using std::string;

class Game {
public:
    
    Game( string home, string visitor, int home_goals, int visitor_goals );
    
    string get_home();
    string get_visitor();
    int get_home_goals();
    int get_visitor_goals();
    
    bool operator==( Game* g );

    string to_string();
private:
    string home;
    string visitor;
    
    int home_goals;
    int visitor_goals;

};

#endif

