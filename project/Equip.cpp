#include <string>
using std::string;

#include "StringProcessor.h"

#include "Equip.h"
#include "Classification.h"

Equip::Equip(string nome){
    this->name = nome;
    this->points = 0;
    this->games = 0;
    this->wins = 0;
    this->draws = 0;
    this->loses = 0;
    this->pro_goals = 0;
    this->sof_goals = 0;
    this->diff_goals = 0;
    this->aproveitamento = 0;
    this->first_game = true;
    this->previous_position = 1;
}

void Equip::set_result(int home_goals, int visitor_goals){
    games++;
    pro_goals += home_goals;
    sof_goals += visitor_goals;
    diff_goals = pro_goals - sof_goals;
    
    if( home_goals > visitor_goals ){
        points += 3;
        wins++;
    }else if( home_goals == visitor_goals ){
        points++;
        draws++;
    }else{
        loses++;
    }
    
    aproveitamento = ( (double) points / ( (double) games * 3) ) * 100;
    
    previous_results[ 0 ] = previous_results[ 1 ];
    previous_results[ 1 ] = previous_results[ 2 ];
    previous_results[ 2 ] = std::to_string( home_goals ) + "-" + std::to_string( visitor_goals );
}

void Equip::set_previous_position(int position){
    this->previous_position = position;
}

string Equip::get_name() {
    return name;
}

int Equip::get_points(){
    return points;
}

int Equip::get_games(){
    return games;
}

int Equip::get_wins(){
    return wins;
}

int Equip::get_draws(){
    return draws;
}

int Equip::get_loses(){
    return loses;
}

int Equip::get_pro_goals(){
    return pro_goals;
}

int Equip::get_sof_goals(){
    return sof_goals;
}

int Equip::get_diff_goals(){
    return diff_goals;
}

double Equip::get_aproveitamento() {
    return aproveitamento;
}

int Equip::get_previous_position(){
    return previous_position;
}

string Equip::to_string(){
    string s = "";
    
    s += "Nome: " + name + '\n';
    s += "Pontos: " + std::to_string( points ) + '\n';
    s += "Jogos: " + std::to_string( games ) + '\n';
    s += "Vitórias: " + std::to_string( wins ) + '\n';
    s += "Empates: " + std::to_string( draws ) + '\n';
    s += "Derrotas: " + std::to_string( loses ) + '\n';
    s += "Gols Pró: : " + std::to_string( pro_goals ) + '\n';
    s += "Gols Sofridos: " + std::to_string( sof_goals ) + '\n';
    s += "Saldo de gols: " + std::to_string( diff_goals ) + '\n';
    s += "Posição anterior: " + std::to_string( previous_position ) + '\n';
    s += "Aproveitamento: " + std::to_string( aproveitamento ) + " %" + '\n';
    
    s += "Resultados anteriores: ";
    for( int i = 0; i < NUMBER_PREVIOUS_RESULTS; i++){
        if( previous_results[ i ] == ""){
            s += " - ";
        }else{
            s += previous_results[ i ] + " ";
        }
    }
    s += '\n';
    
    return s;
}

string Equip::to_latex(){
    string s = "";
    
    s += "&" + ajust_size( 20, name, true);
    s += "&" + std::to_string( points );
    s += "&" + std::to_string( games );
    s += "\t&" + std::to_string( wins );
    s += "&" + std::to_string( draws );
    s += "&" + std::to_string( loses );
    s += "\t&" + std::to_string( pro_goals );
    s += "&" + std::to_string( sof_goals );
    s += "&";
    
    if( diff_goals >= 0 ){
        s += "+";
    }
            
    s += std::to_string( diff_goals );
    s += "\t&";
    if( this->first_game ){
        s += std::to_string( 1 );
        this->first_game = false;
    }else{
        s += std::to_string( previous_position );
    }
    s += "&" + ajust_size( 3, std::to_string( aproveitamento ), false ) + " \\%";
    
    s += "\t&";
    
    for( int i = 0; i < NUMBER_PREVIOUS_RESULTS; i++){
        if( previous_results[ i ] == ""){
            s += " - ";
        }else{
            s += previous_results[ i ] + " ";
        }
    }
    s += "\\\\";
    
    return s;
}