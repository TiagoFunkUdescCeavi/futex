#ifndef TABELA_H
#define TABELA_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Equipe.h"
#include "Jogo.h"
#include "Rodada.h"

enum CRITERIOS{
    PONTOS,
    SALDO_GOLS,
    GOLS_MARCADOS,
    VITORIAS
};
    
class Classificacao{
public:
    
    Classificacao( int numeroRodadas );
    
    bool inserirEquipe( Equipe* e );
    bool inserirJogo( int numeroRodada, Jogo* j );
    
    void inserirCriteriosDesempate( CRITERIOS criterios[] );
    
    void processarRodada( int numeroRodada );
    int getNumeroRodadas();
    void ordenar();
    
    string mostrar();
    string gerarClassificacaoArquivoLatex();
    
private:
    static const int NUMERO_CRITERIOS_DESEMPATE = 4;
    
    vector< Equipe* > equipes;
    vector< Rodada* > rodadas;
    
    CRITERIOS criterios[ NUMERO_CRITERIOS_DESEMPATE ];
    
};

#endif /* TABELA_H */