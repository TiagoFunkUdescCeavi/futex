#include <string>
using std::string;

#include "Game.h"

Game::Game(string home, string visitor, int qty_home_goals, int qty_visitor_goals ) {
    this->home = home;
    this->visitor = visitor;
    this->qty_home_goals = qty_home_goals;
    this->qty_visitor_goals = qty_visitor_goals;
}

string Game::get_home(){
    return this->home;
}

string Game::get_visitor(){
    return this->visitor;
}

int Game::get_qty_home_goals(){
    return this->qty_home_goals;
}

int Game::get_qty_visitor_goals(){
    return this->qty_visitor_goals;
}

void Game::set_home_goal( Goal * goal ){
    this->home_goals.push_back( goal );
}

void Game::set_visitor_goal( Goal * goal ){
    this->visitor_goals.push_back( goal );
}

bool Game::operator ==(Game* g){
    return
        this->home == g->home &&
        this->visitor == g->visitor &&
        this->qty_home_goals == g->qty_home_goals &&
        this->qty_visitor_goals == g->qty_visitor_goals;
}

string Game::to_string(){
    string str = "";
    str += this->home + " ";
    str += std::to_string( this->qty_home_goals ) + "-";
    str += std::to_string( this->qty_visitor_goals) + " ";
    str += this->visitor +"\n";
    for( Goal * g: this->home_goals ){
        str += g->to_string() + "\n";
    }
    for( Goal * g: this->visitor_goals ){
        str += g->to_string() + "\n";
    }
    return str;
}
