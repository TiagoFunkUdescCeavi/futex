#include "Championship.h"

Championship::Championship( string name ){
    this->name = name;
}

void Championship::add_phase( Classification * c ){
    this->phases.push_back( c );
}