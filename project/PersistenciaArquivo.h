#ifndef PERSISTENCIAARQUIVO_H
#define PERSISTENCIAARQUIVO_H

#include <string>
using std::string;

class PersistenciaArquivo {
public:
    PersistenciaArquivo( string nomeArquivo );
    
    void escrever( string s, bool apagar );
    string ler();
    
private:
    string nomeArquivo;
};

#endif /* PERSISTENCIAARQUIVO_H */