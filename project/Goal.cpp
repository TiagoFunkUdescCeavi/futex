#include "Goal.h"
#include <cstdlib>

Goal::Goal( string player, string time, bool penalty, bool own_goal ){
    this->player = player;
    this->time = time;
    this->penalty = penalty;
    this->own_goal = own_goal;
}

bool Goal::operator<( Goal g ){
    string h = this->time;
    if( h.size() == 1 ) h = "0"+h;
    string v = g.time;
    if( v.size() == 1 ) v = "0"+v;
    return h < v;
}

bool Goal::operator>( Goal g ){
    string h = this->time;
    if( h.size() == 1 ) h = "0"+h;
    string v = g.time;
    if( v.size() == 1 ) v = "0"+v;
    return h > v;
}

string Goal::to_string(){
    string str = this->player + " " + this->time;
    if( this->penalty ) str += " (p)";
    if( this->own_goal ) str += " (c)";
    return str;
}