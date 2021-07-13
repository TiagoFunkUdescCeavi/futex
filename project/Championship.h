#ifndef CHAMPIONSHIP_H
#define CHAMPIONSHIP_H

#include "Classification.h"

#include <string>
#include <vector>

using namespace std;

class Championship{
    private:
        string name;
        string latex_text;
        vector< Classification * > phases;

    public:
        Championship( string name );
        void add_phase( Classification * c );

        void process();
        string to_latex();
};

#endif