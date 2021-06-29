#ifndef TIME_H
#define TIME_H

#include <string>
using std::string;

class Equipe {
public:
    Equipe( string nome );
    
    Equipe( string nome, string resultadosAnteriores[], 
        int pontos = 0, int saldoGols = 0, int golsPro = 0, int vitorias = 0, 
        int jogos = 0, int empates = 0, int derrotas = 0, int golsSofridos = 0,
        double aproveitamento = 0, int posicaoAnterior = 0);
    
    void setResultado( int golsDestaEquipe, int golsOutraEquipe );
    
    void setPosicaoAnterior( int posicao );
    
    string getNome();
    int getPontos();
    int getJogos();
    int getVitorias();
    int getEmpates();
    int getDerrotas();
    int getGolsPros();
    int getGolsSofridos();
    int getSaldoGols();
    double getAproveitamento();
    int getPosicaoAnterior();
    
    string editarInformacoes();
    string editarInformacoesArquivoLatex();
    
private:
    static const int NUMERO_RESULTADOS_ANTERIORES = 3;
    
    string nome;
    int pontos;
    
    int jogos;
    int vitorias;
    int empates;
    int derrotas;
    
    int golsPro;
    int golsSofridos;
    int saldoGols;
    
    double aproveitamento;
    int posicaoAnterior;
    string resultadosAnteriores[ NUMERO_RESULTADOS_ANTERIORES ];
    
};

#endif /* TIME_H */