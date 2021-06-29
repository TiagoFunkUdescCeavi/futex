
#ifndef JOGO_H
#define JOGO_H

#include <string>
using std::string;

class Jogo {
public:
    
    Jogo( string mandante, string visitante, int golsMandante, int golsVisitante );
    
    string getMandate();
    string getVisitante();
    int getGolsMandante();
    int getGolsVisitante();
    
    bool operator==( Jogo* j );

    string toString();
private:
    string mandante;
    string visitante;
    
    int golsMandante;
    int golsVisitante;

};

#endif /* JOGO_H */

