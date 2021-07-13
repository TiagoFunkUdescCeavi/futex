#include "Championship.h"

Championship::Championship( string name ){
    this->name = name;
}

void Championship::add_phase( Classification * c ){
    this->phases.push_back( c );
}

void Championship::process(){
    this->latex_text = "";
    for( unsigned int i = 0; i < this->phases.size(); i++ ){
        for( int j = 0; j < this->phases[ i ]->get_number_rounds(); j++ ){
            this->phases[i]->process_round( j+1 );
            this->phases[i]->sort();
            this->latex_text += this->phases[i]->to_latex() + "\n";
        }
    }
}

string Championship::to_latex(){
    return this->latex_text;
}