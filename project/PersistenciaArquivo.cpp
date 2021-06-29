#include <cstdlib>
using std::exit;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

#include <iostream>
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include "PersistenciaArquivo.h"

PersistenciaArquivo::PersistenciaArquivo(string nomeArquivo) {
    this->nomeArquivo = nomeArquivo;
}

void PersistenciaArquivo::escrever(string s, bool apagar ){
    ofstream arq;
    
    if( apagar ){
        arq.open( nomeArquivo.c_str(), ios::out );
    }else{
        arq.open( nomeArquivo.c_str(), ios::app );
    }
    
    if( !arq ){
        cerr << "Erro ao abrir arquivo" << endl;
        exit( 1 );
    }
    
    arq << s << endl;
    
    arq.close();
}

string PersistenciaArquivo::ler(){
    char charAux;
    string leitura = "";
    ifstream arq;
    
    arq.open( nomeArquivo.c_str(), ios::in );
    
    if( !arq ){
        cerr << "Erro ao abrir arquivo !!" << endl;
        exit( 1 );
    }
    
    while( !arq.eof() ){
        charAux = arq.get();
        leitura += charAux;
    }
    
    if( leitura.length() == 1 && charAux == -1 ){
        leitura = "";
    }else{
        leitura = leitura.substr( 0, leitura.length() - 2);
    }
    
    arq.close();
    
    return leitura;
}