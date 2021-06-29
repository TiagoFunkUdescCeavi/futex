#include <string>
using std::string;

#include "Game.h"
#include "Conversor.h"

Game::Game(string home, string visitor, int home_goals, int visitor_goals) {
    this->home = home;
    this->visitor = visitor;
    this->home_goals = home_goals;
    this->visitor_goals = visitor_goals;
}

string Game::get_home(){
    return this->home;
}

string Game::get_visitor(){
    return this->visitor;
}

int Game::get_home_goals(){
    return this->home_goals;
}

int Game::get_visitor_goals(){
    return this->visitor_goals;
}

bool Game::operator ==(Game* g){
    return
        this->home == g->home &&
        this->visitor == g->visitor &&
        this->home_goals == g->home_goals &&
        this->visitor_goals == g->visitor_goals;
}

string Game::to_string(){
    string str = "";
    str += this->home + " ";
    str += std::to_string( this->home_goals ) + " - ";
    str += std::to_string( this->visitor_goals) + " ";
    str += this->visitor;
    return str;
}
