#include "Rodada.h"

Rodada::Rodada() {
}

bool Rodada::inserirJogo(Game* j){
    jogos.push_back( j );
    return true;
}

bool Rodada::removerJogo(Game* j){
    for( int i = 0; i < jogos.size(); i++ ){
        if( j == jogos.at( i ) ){
            jogos.erase( jogos.begin() + i );
            return true;
        }
    }
    return false;
}

vector< Game* > Rodada::getJogos(){
    return jogos;
}
