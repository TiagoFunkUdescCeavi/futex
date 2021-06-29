#include "Rodada.h"

Rodada::Rodada() {
}

bool Rodada::inserirJogo(Jogo* j){
    jogos.push_back( j );
    return true;
}

bool Rodada::removerJogo(Jogo* j){
    for( int i = 0; i < jogos.size(); i++ ){
        if( j == jogos.at( i ) ){
            jogos.erase( jogos.begin() + i );
            return true;
        }
    }
    return false;
}

vector< Jogo* > Rodada::getJogos(){
    return jogos;
}
