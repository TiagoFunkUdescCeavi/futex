#ifndef CHAMPIONSHIP_H
#define CHAMPIONSHIP_H

#include "Phase.h"

#include <string>
#include <vector>

using namespace std;

class Championship{
    private:
        string name;
        string latex_text;
        vector< Phase * > phases;

    public:
        Championship( string name );
        string get_name();
        void add_phase( Phase * c );

        void process();
        string to_latex();
};

#endif