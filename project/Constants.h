#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using std::string;

class Constants{
    public:
        string get_latex_file_header( string title );
        string get_latex_file_footer();
        string get_table_header();
        string get_table_footer();
        string get_section( string s, bool numerable );
        string get_subsection( string s, bool numerable );

        string get_latex_comand( string file );
        string get_portuguese_acents();
};

#endif