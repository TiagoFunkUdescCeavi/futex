#ifndef EDITORSTRING_H
#define EDITORSTRING_H

#include <string>
using std::string;

string ajustarTamanho( int tamanho, string s, bool pos );
string lerTeclado( int tamanhoEsperado = 30);
string arrendondar( double numero );

int comprimento( const char* s );
char charEm( const int posicao, const char* s );
string trim( string s );
string* separar( string s, char separador );

#endif /* EDITORSTRING_H */