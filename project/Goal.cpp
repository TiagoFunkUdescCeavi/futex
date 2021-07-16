#include "Goal.h"

Goal::Goal( string player, string time, bool penalty, bool own_goal ){
    this->player = player;
    this->time = time;
    this->penalty = penalty;
    this->own_goal = own_goal;
}

string Goal::to_string(){
    string str = this->player + " " + this->time;
    if( this->penalty ) str += " (p)";
    if( this->own_goal ) str += " (c)";
    return str;
}