#include <string>
using std::string;

#include "Jogo.h"
#include "Conversor.h"

Jogo::Jogo(string mandante, string visitante, int golsMandante, int golsVisitante) {
    this->mandante = mandante;
    this->visitante = visitante;
    this->golsMandante = golsMandante;
    this->golsVisitante = golsVisitante;
}

string Jogo::getMandate(){
    return mandante;
}

string Jogo::getVisitante(){
    return visitante;
}

int Jogo::getGolsMandante(){
    return golsMandante;
}

int Jogo::getGolsVisitante(){
    return golsVisitante;
}

bool Jogo::operator ==(Jogo* j){
    return
        this->mandante == j->mandante &&
        this->visitante == j->visitante &&
        this->golsMandante == j->golsMandante &&
        this->golsVisitante == j->golsVisitante;
}

string Jogo::toString(){
    string str = mandante + " " + intParaString( golsMandante ) + " - " +
        intParaString( golsVisitante) + " " + visitante;
    return str;
}
