#include <string>
#include <sstream>
#include <istream>
#include <ostream>

using std::string;
using std::ostream;
using std::istream;
using std::ostringstream;
using std::istringstream;

#include "Conversor.h"

string intParaString(int i) {
    string Result; // string que vai retorna o resultado.

    ostringstream convert; // stream usado na conversão

    convert << i; // insire a representação textual de 'Número' nos caracteres no fluxo

    Result = convert.str(); // Realiza a conversão propriamente dita.

    return Result;
}

string doubleParaString(double d){
    string result;

    ostringstream conversor;

    conversor << d;

    result = conversor.str();

    return result;
}

string floatParaString(float f){
    string resultado;

    ostringstream conversor;

    conversor << f;

    resultado = conversor.str();

    return resultado;
}

int stringParaInt(string s){
    int myint;

    istringstream ss(s);
    ss >> myint;

    return myint;
}

double stringParaDouble(string s){
    istringstream i(s);
    double numero;
    if (!(i >> numero)) {
        return 0;
    }
    return numero;
}

float stringParaFloat(string s){
    istringstream i(s);
    float numero;
    if (!(i >> numero)) {
        return 0;
    }
    return numero;
}