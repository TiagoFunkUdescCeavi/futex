#include <string>
using std::string;

#include <iostream>

#include <exception>
using std::exception;

#include "ProcessadorString.h"
#include "Classificacao.h"
#include "PersistenciaArquivo.h"

#include "ProcessadorArquivo.h"
#include "Conversor.h"

ProcessadorArquivo::ProcessadorArquivo( string nomeArquivo ) {
    this->nomeArquivo = nomeArquivo;
}

Classificacao* ProcessadorArquivo::processar() throw (exception) {
    bool sucesso = true;
    int numeroLinha = 1;
    string linha = "", info;
    PersistenciaArquivo* p = new PersistenciaArquivo( nomeArquivo );
    
    info = p->ler();

    for (int i = 0; i < info.length(); i++) {
        if( info[ i ] == '\n' || i-1 == info.length() ){
            try{
                processarLinha( numeroLinha, linha );
            }catch ( exception &exception ){
                sucesso = false;
            }
            linha = "";
            numeroLinha++;
        }else{
            linha += info[ i ];
        }
    }
    try{
        processarLinha( numeroLinha, linha );
    }catch ( exception &exception ){
        sucesso = false;
    }
    
    if( !sucesso ){
        std::cerr << "DEVIDO AO ERRO DE SINTAXE, A GERAÇÃO DA TABELA FOI ABORTADO." << std::endl;
        throw exception();
    }
    
    return this->classificacao;
}

void ProcessadorArquivo::processarLinha( int numeroLinha, string linha) throw ( exception ) {
    if( linha.empty() || linha == "\n" || linha.substr( 0, 2 ) == "//" ){
        return ;
    }

    string comando, valores;

    // 18446744073709551615
    // Valor para quando o find não encontra a ocorrência.
    if( linha.find( ":" ) == 18446744073709551615 ){
        std::cerr << "Linha " << numeroLinha << 
                " - Token \':\' não foi encontrado: " << linha << std::endl;
        throw exception();
    }else{
        comando = trim( linha.substr( 0, linha.find( ':', 0 ) ) );
        valores = trim( linha.substr( linha.find( ":" ) + 1 ) );
    }

    if( comando == "alias" ){
        string alias, nome;
        alias = valores.substr( 0, valores.find( " ", 0 ) );
        nome = valores.substr( valores.find( " ", 0 ) + 1 );
        
        aliases.insert( HashMap::value_type( alias, nome ) );
        std::cout << "Alias adicionado: " << alias << " - " << nome << std::endl;
        
    }else if( comando == "rodada" ){
        rodadaAtual = stringParaInt( trim( valores ) );
        std::cout << "Nova rodada: " << rodadaAtual << std::endl;
        
    }else if( comando == "jogo" ){
        int numeroArgumentos = 0;
        string* argumentos = separar( numeroArgumentos, valores, ' ' );
        Game* j = new Game( aliases[ argumentos[ 0 ] ], aliases[ argumentos[ 1 ] ], 
            stringParaInt( argumentos[ 2 ] ), stringParaInt( argumentos[ 3 ] ) );
        classificacao->inserirJogo( rodadaAtual, j );
        std::cout << "Jogo adicionado: " << j->to_string() << std::endl;
        
    }else if( comando == "campeonato" ){
        classificacao = new Classificacao( stringParaInt( trim( valores ) ) );
        for( HashMap::const_iterator iter = aliases.begin(); iter != aliases.end(); iter++ ){
            classificacao->inserirEquipe( new Equipe( iter->second ) );
        }
        std::cout << "Campenato criado: " << valores << " rodadas" << std::endl;
        
    }else{
        std::cerr << "Linha " << numeroLinha <<
                " - Comando não encontrado: " << comando << std::endl;
        throw exception();
    }

}
