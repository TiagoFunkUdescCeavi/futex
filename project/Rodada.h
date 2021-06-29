#ifndef RODADA_H
#define RODADA_H

#include <vector>
using std::vector;

#include "Game.h"

class Rodada {
public:
    
    Rodada();
    
    bool inserirJogo( Game* j );
    bool removerJogo( Game* j );
    
    vector< Game* > getJogos();
    
private:
    vector< Game* > jogos;
};

#endif /* RODADA_H */

