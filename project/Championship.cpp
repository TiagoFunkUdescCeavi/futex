#include "Championship.h"
#include "Messenger.h"

Championship::Championship( string name ){
    this->name = name;
}

string Championship::get_name(){
    return this->name;
}

void Championship::add_phase( Phase * c ){
    this->phases.push_back( c );
}

void Championship::process(){
    this->latex_text = "";
    for( unsigned int i = 0; i < this->phases.size(); i++ ){
        this->latex_text += Messenger::instance()->latex_section( this->phases[i]->get_name(), false );
        this->phases[ i ]->process();
        this->latex_text += this->phases[ i ]->to_latex() + "\n";
    }
}

string Championship::to_latex(){
    return this->latex_text;
}