#ifndef PHASE_H
#define PHASE_H

#include <string>
#include <vector>

using namespace std;

#include "Instance.h"

class Phase{
    private:
        string name;
        string latex_text;
        vector< Instance * > instances;

    public:
        Phase( string name );
        string get_name();
        void add_instance( Instance * i );

        void process();
        string to_latex();
};

#endif