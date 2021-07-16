#ifndef PHASE_H
#define PHASE_H

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
    
class Phase{
public:
    
    Phase( string name );
    string get_name();
    
    bool insert_equip( Equip* e );
    bool insert_game( int round, Game* g );
    
    void inserirCriteriosDesempate( CRITERIOS criterios[] );
    
    void create_new_round();
    void process_round( int round );
    int get_number_rounds();
    void sort();
    
    string to_string();
    string to_latex();
    
private:
    static const int NUMERO_CRITERIOS_DESEMPATE = 4;

    int actual_round;
    string name;
    
    vector< Equip* > equips;
    vector< Round* > rounds;
    
    CRITERIOS criterios[ NUMERO_CRITERIOS_DESEMPATE ];
    
};

#endif