#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Equip.h"
#include "Game.h"
#include "Round.h"

enum CRITERIOS{
    POINTS,
    DIFF_GOALS,
    PRO_GOALS,
    WINS
};
    
class Classification{
public:
    
    Classification( int rounds );
    
    bool insert_equip( Equip* e );
    bool insert_game( int round, Game* g );
    
    void inserirCriteriosDesempate( CRITERIOS criterios[] );
    
    void process_round( int round );
    int get_number_rounds();
    void sort();
    
    string to_string();
    string to_latex();
    
private:
    static const int NUMERO_CRITERIOS_DESEMPATE = 4;
    
    vector< Equip* > equips;
    vector< Round* > rounds;
    
    CRITERIOS criterios[ NUMERO_CRITERIOS_DESEMPATE ];
    
};

#endif