#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

#include "Instance.h"
#include "Messenger.h"

using namespace std;

Instance::Instance( string name ) {
    this->name = name;
    this->actual_round = 0;
    this->criterios[ 0 ] = POINTS;
    this->criterios[ 1 ] = DIFF_GOALS;
    this->criterios[ 2 ] = PRO_GOALS;
    this->criterios[ 3 ] = WINS;
}

string Instance::get_name(){
    return this->name;
}

bool Instance::insert_equip(Equip* e) {
    for( unsigned int i = 0; i < this->equips.size(); i++ ){
        if( e->get_name() == this->equips.at( i )->get_name() ){
            return false;
        }
    }
    this->equips.push_back( e );
    return true;
}

bool Instance::insert_game( int round, Game* g ){
    this->check_if_round_is_valid( round );
    return this->rounds[ round-1 ]->insert_game( g );
}

void Instance::inserirCriteriosDesempate( CRITERIOS criterios[] ){
    for( int i = 0; i < NUMERO_CRITERIOS_DESEMPATE; i++){
        this->criterios[ i ] = criterios[ i ];
    }
}

void Instance::create_new_round(){
    this->rounds.push_back( new Round() );
}

void Instance::process_round(int round){
    this->check_if_round_is_valid( round );
    
    Game * game = 0;
    Equip * equip = 0;
    this->actual_round = round - 1;
    vector< Game* > games = this->rounds[ this->actual_round ]->get_games();
    
    for (unsigned int i = 0; i < games.size(); i++) {
        game = games[ i ];
        for ( unsigned int j = 0; j < equips.size(); j++) {
            equip = this->equips[ j ];
            if( equip->get_name() == game->get_home() ){
                equip->set_result( game->get_qty_home_goals(), game->get_qty_visitor_goals() );
            }else if( equip->get_name() == game->get_visitor() ){
                equip->set_result( game->get_qty_visitor_goals(), game->get_qty_home_goals() );
            }
        }
    }
    this->sort();
}
    
int Instance::get_number_rounds(){
    return this->rounds.size();
}

string Instance::to_string(){
    int size = this->equips.size();
    
    if( size == 0 ) return Messenger::instance()->phase_empty();

    string s = "";
    for (int i = 0; i < size; i++) {
        s += std::to_string( i+1 ) + "??" + this->equips[ i ]->to_latex() + '\n';
    }
    return s;
}

string Instance::to_latex(){
    string s = Messenger::instance()->latex_subsection( "Rodada " + std::to_string( this->actual_round + 1 ), false );
    vector< Game * > games = this->rounds[ this->actual_round ]->get_games();
    for( unsigned int i = 0; i < games.size(); i++ ){
        s += games[ i ]->to_string() + "\\\\\n";
    }
    s += Messenger::instance()->latex_table_header();
    for( unsigned int i = 0; i < this->equips.size(); i++ ){
        s += std::to_string( i+1 ) + "??" + this->equips[ i ]->to_latex() + '\n';
    }
    s += Messenger::instance()->latex_table_footer();
    s += "\n";
    return s;
}

void Instance::check_if_round_is_valid( int round ){
    int size = this->rounds.size();
    if( round < 1 || round > size ){
        throw runtime_error( Messenger::instance()->round_value_is_invalid( __FILE__, __LINE__, round ) );
    }
}

void Instance::sort() {
    int diff;
    this->save_previous_position();
    for (unsigned int i = 0; i < this->equips.size(); i++) {
        for (unsigned int j = i+1; j < this->equips.size(); j++) {
            diff = this->difference_equips( this->equips[ i ], this->equips[ j ] );
            if( diff < 0 ) this->swap_equips( i, j );
        }
    }
}

int Instance::difference_equips( Equip * i, Equip * j ){
    int diff = 0;
    for (int k = 0; k < this->NUMERO_CRITERIOS_DESEMPATE; k++) {
        switch( criterios[ k ] ){
            case POINTS:
                diff = i->get_points() - j->get_points();
                break;
            case DIFF_GOALS:
                diff = i->get_diff_goals() - j->get_diff_goals();
                break;
            case PRO_GOALS:
                diff = i->get_pro_goals() - j->get_pro_goals();
                break;
            case WINS:
                diff = i->get_wins() - j->get_wins();
                break;
            default:
                throw runtime_error( Messenger::instance()->sort_criterion_not_found( __FILE__, __LINE__ ) );
        }
        if( diff != 0 ) break;
    }
    return diff;
}

void Instance::swap_equips( int i, int j ){
    Equip* e = this->equips[ i ];
    this->equips[ i ] = this->equips[ j ]; 
    this->equips[ j ] = e;
}

void Instance::save_previous_position(){
    for( unsigned int i = 0; i < this->equips.size(); i++ ){
        this->equips[i]->set_previous_position( i+1 );
    }
}