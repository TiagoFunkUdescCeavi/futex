#ifndef CHAMPIONSHIP_H
#define CHAMPIONSHIP_H

#include "Classification.h"

#include <string>
#include <vector>

using namespace std;

class Championship{
    private:
        string name;
        vector< Classification * > phases;

    public:
        Championship( string name );
        void add_phase( Classification * c );
};

#endif