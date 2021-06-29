#ifndef PROCESSADORARQUIVO_H
#define PROCESSADORARQUIVO_H

#include <string>
using std::string;

#include <map>
using std::map;
using std::less;

#include <exception>
using std::exception;

#include "Classification.h"

class ProcessadorArquivo {
public:
    ProcessadorArquivo( string nomeArquivo );
    
    Classification* processar() throw (exception);
private:
    const string CAMPEONATO = "campeonato";
    const string RODADA = "rodada";
    const string JOGO = "jogo";
    const string ALIAS = "alias";
    
    int rodadaAtual;
    string nomeArquivo;
    Classification* classificacao;
    
    typedef map< string, string, less< string > > HashMap;
    HashMap aliases;
    
    void processarLinha( int numeroLinha, string linha ) throw ( exception );
};

#endif /* PROCESSADORARQUIVO_H */

