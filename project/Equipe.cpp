#include <string>
using std::string;

#include "Conversor.h"
#include "ProcessadorString.h"

#include "Equipe.h"
#include "Classificacao.h"

Equipe::Equipe(string nome){
    this->nome = nome;
}

Equipe::Equipe(string nome, string resultadosAnteriores[], 
        int pontos, int saldoGols, int golsPro, int vitorias, int jogos,
        int empates, int derrotas, int golsSofridos, 
        double aproveitamento, int posicaoAnterior) {
    this->nome = nome;
    this->pontos = pontos;

    this->jogos = jogos;
    this->vitorias = vitorias;
    this->empates = empates;
    this->derrotas = derrotas;

    this->golsPro = golsPro;
    this->golsSofridos = golsSofridos;
    this->saldoGols = saldoGols;

    this->aproveitamento = aproveitamento;
    this->posicaoAnterior = posicaoAnterior;
    
    for( int i = 0; i < NUMERO_RESULTADOS_ANTERIORES; i++){
        this->resultadosAnteriores[ i ] = resultadosAnteriores [ i ];
    }
}

void Equipe::setResultado(int golsDestaEquipe, int golsOutraEquipe){
    jogos++;
    golsPro += golsDestaEquipe;
    golsSofridos += golsOutraEquipe;
    saldoGols = golsPro - golsSofridos;
    
    if( golsDestaEquipe > golsOutraEquipe ){
        pontos += 3;
        vitorias++;
    }else if( golsDestaEquipe == golsOutraEquipe ){
        pontos++;
        empates++;
    }else{
        derrotas++;
    }
    
    aproveitamento = ( (double) pontos / ( (double) jogos * 3) ) * 100;
    
    resultadosAnteriores[ 0 ] = resultadosAnteriores[ 1 ];
    resultadosAnteriores[ 1 ] = resultadosAnteriores[ 2 ];
    resultadosAnteriores[ 2 ] = intParaString( golsDestaEquipe ) + "-" + intParaString( golsOutraEquipe );
}

void Equipe::setPosicaoAnterior(int posicao){
    this->posicaoAnterior = posicao;
}

string Equipe::getNome() {
    return nome;
}

int Equipe::getPontos(){
    return pontos;
}

int Equipe::getJogos(){
    return jogos;
}

int Equipe::getVitorias(){
    return vitorias;
}

int Equipe::getEmpates(){
    return empates;
}

int Equipe::getDerrotas(){
    return derrotas;
}

int Equipe::getGolsPros(){
    return golsPro;
}

int Equipe::getGolsSofridos(){
    return golsSofridos;
}

int Equipe::getSaldoGols(){
    return saldoGols;
}

double Equipe::getAproveitamento() {
    return aproveitamento;
}


int Equipe::getPosicaoAnterior(){
    return posicaoAnterior;
}

string Equipe::editarInformacoes(){
    string s = "";
    
    s += "Nome: " + nome + '\n';
    s += "Pontos: " + intParaString( pontos ) + '\n';
    s += "Jogos: " + intParaString( jogos ) + '\n';
    s += "Vitórias: " + intParaString( vitorias ) + '\n';
    s += "Empates: " + intParaString( empates ) + '\n';
    s += "Derrotas: " + intParaString( derrotas ) + '\n';
    s += "Gols Pró: : " + intParaString( golsPro ) + '\n';
    s += "Gols Sofridos: " + intParaString( golsSofridos ) + '\n';
    s += "Saldo de gols: " + intParaString( saldoGols ) + '\n';
    s += "Posição anterior: " + intParaString( posicaoAnterior ) + '\n';
    s += "Aproveitamento: " + doubleParaString( aproveitamento ) + " %" + '\n';
    
    s += "Resultados anteriores: ";
    for( int i = 0; i < NUMERO_RESULTADOS_ANTERIORES; i++){
        if( resultadosAnteriores[ i ] == ""){
            s += " - ";
        }else{
            s += resultadosAnteriores[ i ] + " ";
        }
    }
    s += '\n';
    
    return s;
}

string Equipe::editarInformacoesArquivoLatex(){
    string s = "";
    
    s += "&" + ajustarTamanho( 20, nome, true);
    s += "&" + intParaString( pontos );
    s += "&" + intParaString( jogos );
    s += "\t&" + intParaString( vitorias );
    s += "&" + intParaString( empates );
    s += "&" + intParaString( derrotas );
    s += "\t&" + intParaString( golsPro );
    s += "&" + intParaString( golsSofridos );
    s += "&";
    
    if( saldoGols >= 0 ){
        s += "+";
    }
            
    s += intParaString( saldoGols );
    s += "\t&" + intParaString( posicaoAnterior );
    s += "&" + ajustarTamanho( 3, doubleParaString( aproveitamento ), false ) + " %";
    
    s += "\t&";
    
    for( int i = 0; i < NUMERO_RESULTADOS_ANTERIORES; i++){
        if( resultadosAnteriores[ i ] == ""){
            s += " - ";
        }else{
            s += resultadosAnteriores[ i ] + " ";
        }
    }
    s += "\\\\";
    
    return s;
}