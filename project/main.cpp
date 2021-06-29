#include <iostream>
using std::cout;
using std::endl;

#include <stdlib.h>

#include <string>
using std::string;

#include "Classificacao.h"
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
        Classificacao* c = pl->processar();
        for (int i = 1; i <= c->getNumeroRodadas(); i++) {
            c->processarRodada( i );
            c->ordenar();
            pa->escrever( c->gerarClassificacaoArquivoLatex(), false );
        }

    }catch( exception &ex ){
        cout << ex.what() << endl;
    }

    return 0;
}
