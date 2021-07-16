#include <iostream>
using std::cout;
using std::endl;

#include <stdlib.h>

#include <string>
using std::string;

#include "Constants.h"
#include "Championship.h"
#include "FileProcessor.h"
#include "StringProcessor.h"
#include "File.h"

int main( int argc, char** argv ) {

    if( argc != 2 ){
        cout << "Entrada esperada: ./futex <input_file>" << endl;
        exit( 1 );
    }

    string input_file( argv[ 1 ] );
    string output_file = input_file.substr( 0, input_file.find_last_of(".") ) + ".tex";
    
    FileProcessor* fp = new FileProcessor( input_file );
    
    File* f = new File( output_file );
    
    f->write( "", true );
    try{
        Championship * c = fp->process();
        c->process();
        f->write( (new Constants())->get_latex_file_header( c->get_name() ), false );
        f->write( c->to_latex(), false );
        f->write( (new Constants())->get_latex_file_footer(), false );

    }catch( exception &ex ){
        cout << ex.what() << endl;
    }

    string str = (new Constants())->get_latex_comand( input_file.substr( 0, input_file.find_last_of(".") ) );
    system( str.c_str() );

    return 0;
}
