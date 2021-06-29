#ifndef RODADA_H
#define RODADA_H

#include <vector>
using std::vector;

#include "Game.h"

class Round {
public:
    
    Round();
    
    bool insert_game( Game* g );
    bool remove_game( Game* g );
    
    vector< Game* > get_games();
    
private:
    vector< Game* > games;
};

#endif

