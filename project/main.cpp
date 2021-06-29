#include <iostream>
using std::cout;
using std::endl;

#include <stdlib.h>

#include <string>
using std::string;

#include "Classification.h"
#include "ProcessadorArquivo.h"
#include "ProcessadorString.h"
#include "PersistenciaArquivo.h"

int main( int argc, char** argv ) {

    if( argc != 3 ){
        cout << "Entrada esperada: ./futex <input_file> <output_file>" << endl;
        exit( 1 );
    }

    string input_file( argv[ 1 ] );
    string output_file( argv[ 2 ] );
    
    ProcessadorArquivo* pl = new ProcessadorArquivo( input_file );
    
    PersistenciaArquivo* pa = new PersistenciaArquivo( output_file );
    
    pa->escrever( "", true );
    try{
        Classification* c = pl->processar();
        for (int i = 1; i <= c->get_number_rounds(); i++) {
            c->process_round( i );
            c->sort();
            pa->escrever( c->to_latex(), false );
        }

    }catch( exception &ex ){
        cout << ex.what() << endl;
    }

    return 0;
}
