#include <iostream>
using std::cout;
using std::endl;

#include <stdlib.h>

#include <string>
using std::string;

#include "Classification.h"
#include "FileProcessor.h"
#include "StringProcessor.h"
#include "File.h"

int main( int argc, char** argv ) {

    if( argc != 3 ){
        cout << "Entrada esperada: ./futex <input_file> <output_file>" << endl;
        exit( 1 );
    }

    string input_file( argv[ 1 ] );
    string output_file( argv[ 2 ] );
    
    FileProcessor* pl = new FileProcessor( input_file );
    
    File* f = new File( output_file );
    
    f->write( "", true );
    try{
        Classification* c = pl->process();
        for (int i = 1; i <= c->get_number_rounds(); i++) {
            c->process_round( i );
            c->sort();
            f->write( c->to_latex(), false );
        }

    }catch( exception &ex ){
        cout << ex.what() << endl;
    }

    return 0;
}
