#include "Phase.h"
#include "Messenger.h"

Phase::Phase( string name ){
    this->name = name;
}

string Phase::get_name(){
    return this->name;
}

void Phase::add_instance( Instance * i ){
    this->instances.push_back( i );
}

void Phase::process(){
    this->latex_text = "";
    for( unsigned int i = 0; i < this->instances.size(); i++ ){
        this->latex_text += Messenger::instance()->latex_subsection( this->instances[ i ]->get_name(), false );
        for( int j = 0; j < this->instances[ i ]->get_number_rounds(); j++ ){
            this->instances[i]->process_round( j+1 );
            this->latex_text += this->instances[i]->to_latex() + "\n";
        }
    }
}

string Phase::to_latex(){
    return this->latex_text;
}