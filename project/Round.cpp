#include "Round.h"

Round::Round() {
}

bool Round::insert_game(Game* g){
    this->games.push_back( g );
    return true;
}

bool Round::remove_game(Game* g){
    for( unsigned int i = 0; i < this->games.size(); i++ ){
        if( g == this->games[ i ] ){
            this->games.erase( this->games.begin() + i );
            return true;
        }
    }
    return false;
}

vector< Game* > Round::get_games(){
    return this->games;
}
