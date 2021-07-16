#ifndef MESSENGER_H
#define MESSENGER_H

#include <string>
using std::string;

class Messenger{
    private:
        static Messenger * _instance;

    protected:
        Messenger();
        
    public:
        static Messenger * instance();

        string latex_file_header( string title );
        string latex_file_footer();
        string latex_table_header();
        string latex_table_footer();
        string latex_section( string s, bool numerable );
        string latex_subsection( string s, bool numerable );

        string latex_comand( string file );
        string portuguese_acents();

        string error_on_open_file( string file );
        string file_is_empty( string file );
        string command_not_found( int line, string command );
        string token_not_found( int line, string command );

        string round_value_is_invalid( string cpp_file, int cpp_file_line, int round_value );
        string sort_criterion_not_found( string cpp_file, int cpp_file_line );
        string expected_input();
        string phase_empty();
};

#endif