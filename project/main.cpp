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
    
    ProcessadorArquivo* pl = new ProcessadorArquivo( "./teste.txt");
    
    PersistenciaArquivo* pa = new PersistenciaArquivo("./resultado.txt");
    
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
