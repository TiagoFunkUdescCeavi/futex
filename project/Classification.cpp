#include <vector>

#include <string>

#include <iostream>

#include <cstdlib>

#include "Classification.h"
#include "Conversor.h"

using namespace std;

Classification::Classification( int rounds ) {
    for( int i = 0; i < rounds; i++ ){
        this->rounds.push_back( new Rodada() );
    }
    this->criterios[ 0 ] = POINTS;
    this->criterios[ 1 ] = DIFF_GOALS;
    this->criterios[ 2 ] = PRO_GOALS;
    this->criterios[ 3 ] = WINS;
}

bool Classification::insert_equip(Equip* e) {
    for( unsigned int i = 0; i < this->equips.size(); i++ ){
        if( e->get_name() == this->equips.at( i )->get_name() ){
            return false;
        }
    }
    this->equips.push_back( e );
    return true;
}

bool Classification::insert_game( int round, Game* g ){
    int size = this->rounds.size();
    if( round < 1 || round > size ){
        throw runtime_error( "insert_game: \"round\" value is invalid: " + std::to_string( round ) + "\n");
    }
    return this->rounds.at( round-1 )->inserirJogo( g );
}

void Classification::inserirCriteriosDesempate(CRITERIOS criterios[] ){
    for( int i = 0; i < NUMERO_CRITERIOS_DESEMPATE; i++){
        this->criterios[ i ] = criterios[ i ];
    }
}

void Classification::process_round(int round){
    int size = this->rounds.size();
    if( round < 1 || round > size ){
        throw runtime_error( "process_round: \"round\" value is invalid: " + std::to_string( round ) + "\n" );
    }
    
    Game * game = 0;
    Equip * equip = 0;
    vector< Game* > games = this->rounds.at( round-1 )->getJogos();
    
    for (unsigned int i = 0; i < games.size(); i++) {
        game = games[ i ];
        for ( unsigned int j = 0; j < equips.size(); j++) {
            equip = equips[ j ];
            if( equip->get_name() == game->get_home() ){
                equip->set_result( game->get_home_goals(), game->get_visitor_goals() );
            }else if( equip->get_name() == game->get_visitor() ){
                equip->set_result( game->get_visitor_goals(), game->get_home_goals() );
            }
        }
    }
    
}
    
int Classification::get_number_rounds(){
    return this->rounds.size();
}

void Classification::sort() {
    int diff;
    for (unsigned int i = 0; i < this->equips.size(); i++) {
        for (unsigned int j = i+1; j < this->equips.size(); j++) {
            for (int k = 0; k < this->NUMERO_CRITERIOS_DESEMPATE; k++) {
                switch( criterios[ k ] ){
                    case POINTS:
                        diff = this->equips[ i ]->get_points() - this->equips[ j ]->get_points();
                        break;
                    case DIFF_GOALS:
                        diff = this->equips[ i ]->get_diff_goals() - this->equips[ j ]->get_diff_goals();
                        break;
                    case PRO_GOALS:
                        diff = this->equips[ i ]->get_pro_goals() - this->equips[ j ]->get_pro_goals();
                        break;
                    case WINS:
                        diff = this->equips[ i ]->get_wins() - this->equips[ j ]->get_wins();
                        break;
                    default:
                        throw runtime_error("sort: Critério de desempate não foi encontrado.\n");
                }
                
                if( diff < 0 ){
                    Equip* e = this->equips[ i ];
                    this->equips[ i ] = this->equips[ j ]; 
                    this->equips[ j ] = e;
                    break;
                }else if( diff > 0 ){
                    break;
                }
            }
        }
    }

}

string Classification::to_string(){
    int size = this->equips.size();
    
    if( size == 0 ){
        return "Nenhuma equipe nesta classificação";
    }
    string s = "";
    for (int i = 0; i < size; i++) {
        s += std::to_string( i+1 ) + "º" + this->equips.at(i)->to_latex() + '\n';
    }
    return s;
}


string Classification::to_latex(){
    int size = this->equips.size();
    string s = "";
    for( int i = 0; i < size; i++ ){
        s += std::to_string( i+1 ) + "º" + this->equips.at( i )->to_latex() + '\n';
    }
    s += "\n\n\n";
    return s;
}