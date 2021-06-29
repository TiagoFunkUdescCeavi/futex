#ifndef RODADA_H
#define RODADA_H

#include <vector>
using std::vector;

#include "Jogo.h"

class Rodada {
public:
    
    Rodada();
    
    bool inserirJogo( Jogo* j );
    bool removerJogo( Jogo* j );
    
    vector< Jogo* > getJogos();
    
private:
    vector< Jogo* > jogos;
};

#endif /* RODADA_H */

