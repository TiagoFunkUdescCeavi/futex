#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>

#include <cstdlib>

#include "Classification.h"
#include "Conversor.h"

Classification::Classification( int rounds ) {
    for( int i = 0; i < rounds; i++ ){
        this->rounds.push_back( new Rodada() );
    }
}

bool Classification::insert_equip(Equip* e) {
    for( int i = 0; i < this->equips.size(); i++ ){
        if( e->get_name() == equips.at( i )->get_name() ){
            return false;
        }
    }
    equips.push_back( e );
    return true;
}

bool Classification::insert_game( int round, Game* g ){
    if( round < 1 || round > rounds.size() ){
        std::cerr << "numeroRodada inválido: " << round << std::endl;
        exit( 1 );
    }
    return rounds.at( round-1 )->inserirJogo( g );
}

void Classification::inserirCriteriosDesempate(CRITERIOS criterios[] ){
    for( int i = 0; i < NUMERO_CRITERIOS_DESEMPATE; i++){
        this->criterios[ i ] = criterios[ i ];
    }
}

void Classification::process_round(int round){
    if( round < 1 || round > rounds.size() ){
        std::cerr << "numeroRodada inválido: " << round << std::endl;
        exit( 1 );
    }
    
    Game* game;
    Equip* equip;
    vector< Game* > games = rounds.at( round-1 )->getJogos();
    
    for (int i = 0; i < games.size(); i++) {
        game = games.at( i );
        for (int j = 0; j < equips.size(); j++) {
            equip = equips.at( j );
            if( equip->get_name() == game->get_home() ){
                equip->set_result( game->get_home_goals(), game->get_visitor_goals() );
            }else if( equip->get_name() == game->get_visitor() ){
                equip->set_result( game->get_visitor_goals(), game->get_home_goals() );
            }
        }
    }
    
}
    
int Classification::get_number_rounds(){
    return rounds.size();
}

void Classification::sort() {
    int valorA = 0, valorB = 0;
    for (int i = 0; i < equips.size(); i++) {
        for (int j = i+1; j < equips.size(); j++) {
            for (int k = 0; k < NUMERO_CRITERIOS_DESEMPATE; k++) {
                switch( criterios[ k ] ){
                    case POINTS:
                        valorA = equips.at( i )->get_points();
                        valorB = equips.at( j )->get_points();
                        break;
                    
                    case DIFF_GOALS:
                        valorA = equips.at( i )->get_diff_goals();
                        valorB = equips.at( j )->get_diff_goals();
                        break;
                        
                    case PRO_GOALS:
                        valorA = equips.at( i )->get_pro_goals();
                        valorB = equips.at( j )->get_pro_goals();
                        break;
                        
                    case WINS:
                        valorA = equips.at( i )->get_wins();
                        valorB = equips.at( j )->get_wins();
                        break;
                }
                
                if( valorA < valorB ){
                    Equip* e = equips.at( i );
                    equips[ i ] = equips[ j ]; 
                    equips[ j ] = e;
                    break;
                }else if( valorA > valorB ){
                    break;
                }
            }
        }
    }

}

string Classification::to_string(){
    int size = equips.size();
    
    if( size == 0 ){
        return "Nenhuma equipe nesta classificação";
    }
    string s = "";
    for (int i = 0; i < size; i++) {
        s += std::to_string( i+1 ) + "º" + equips.at(i)->to_latex() + '\n';
    }
    return s;
}


string Classification::to_latex(){
    int size = equips.size();
    string s = "";
    for( int i = 0; i < size; i++ ){
        s += std::to_string( i+1 ) + "º" + equips.at( i )->to_latex() + '\n';
    }
    s += "\n\n\n";
    return s;
}