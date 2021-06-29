#include <iostream>
using std::cin;

#include <string>
using std::string;

#include <cstdlib>

#include "Conversor.h"

#include "ProcessadorString.h"

string ajustarTamanho(int tamanho, string s, bool pos ){
    if( tamanho < s.length() ){
        return s.substr( 0, tamanho-1 );
    }
    for( int i = s.length(); i < tamanho; i++){
        if( pos ){
            s = s + " ";
        }else{
            s = " " + s;
        }
    }
    return s;
}

string lerTeclado( int tamanhoEsperado ){
    char aux[ tamanhoEsperado ];
    string s;
    cin.getline( aux, tamanhoEsperado );
    s = aux;
    return s;
}

string arrendondar( double numero ){
    int valor = numero;
    return intParaString( numero );
}

int comprimento( const char* s ){
    if( s == 0 ){
        std::cerr << "ProcessadorString.cpp: const char* s não pode "
                "ser nulo na função comprimento." << std::endl;
        exit( 1 );
    }
    int tamanho = 0;
    for (int i = 0; ; i++) {
        if( s[ i ] == '\0' ){
            tamanho = i;
            break;
        }
    }
    return tamanho;
}

char charEm(const int posicao, const char* s ){
    if( s == 0 ){
        std::cerr << "ProcessadorString.cpp: const char* s não pode "
                "ser nulo na função charEm." << std::endl;
        exit( 1 );
    }
    char retorno = 0;
    int tamanho = 0;
    for (int i = 0; ; i++) {
        if( s[ i ] == '\0' ){
            tamanho = i;
            break;
        }
        if( i == posicao ){
            retorno = s[ i ];
            tamanho = i;
            break;
        }
    }
    if( retorno == 0 ){
        std::cerr << "ProcessadorString.cpp: posição <" << posicao <<
                "> é inválido que o comprimento de s<" << tamanho << ">." << std::endl;
        exit( 1 );
    }
    return retorno;
}

string trim( string s ){
    bool encontrouAlgo = false;
    int i;
    int inicio = 0, termino = 0;
    
    for ( i = 0; i < s.length(); i++ ) {
        if( s[ i ] != ' ' ){
            inicio = i;
            encontrouAlgo = true;
            break;
        }
    }
    if( !encontrouAlgo ){
        return "";
    }
    for ( i = s.length() - 1; i >= 0; i-- ) {
        if( s[ i ] != ' ' ){
            termino = i;
            break;
        }
    }
    
    return s.substr( inicio, termino-inicio+1 );
}

string* separar( int &tamanhoVetor, string s, char separador ){
    int tamanho = 0;
    char aux;
    string* vetor = 0;
    
    s = trim( s );
    
    for (int i = 0; i <= ( s.length() - 1 ); i++) {
        aux = s[ i ];
        if( aux == separador ){
            tamanho++;
        }
    }
    tamanho++;
    tamanhoVetor = tamanho;
    vetor = new string[ tamanho ];
    
    int contador = 0;
    int posicaoInicial = 0;
    for (int i = 0; i <= ( s.length() - 1 ); i++) {
        aux = s[ i ];
        if( aux == separador ){
            vetor[ contador ] = s.substr( posicaoInicial, i-posicaoInicial );
            contador++;
            posicaoInicial = i + 1;
        }
    }
    vetor[ contador ] = s.substr( s.rfind( separador )+1 );
    
    return vetor;
}