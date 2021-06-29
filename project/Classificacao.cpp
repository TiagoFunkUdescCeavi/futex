#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>

#include <cstdlib>

#include "Classificacao.h"
#include "Conversor.h"

Classificacao::Classificacao( int numeroRodadas) {
    for( int i = 0; i < numeroRodadas; i++ ){
        rodadas.push_back( new Rodada() );
    }
}

bool Classificacao::inserirEquipe(Equip* e) {
    for( int i = 0; i < equipes.size(); i++ ){
        if( e->get_name() == equipes.at( i )->get_name() ){
            return false;
        }
    }
    equipes.push_back( e );
    return true;
}

bool Classificacao::inserirJogo( int numeroRodada, Game* j ){
    if( numeroRodada < 1 || numeroRodada > rodadas.size() ){
        std::cerr << "numeroRodada inválido: " << numeroRodada << std::endl;
        exit( 1 );
    }
    return rodadas.at( numeroRodada-1 )->inserirJogo( j );
}

void Classificacao::inserirCriteriosDesempate(CRITERIOS criterios[] ){
    for( int i = 0; i < NUMERO_CRITERIOS_DESEMPATE; i++){
        this->criterios[ i ] = criterios[ i ];
    }
}

void Classificacao::processarRodada(int numeroRodada){
    if( numeroRodada < 1 || numeroRodada > rodadas.size() ){
        std::cerr << "numeroRodada inválido: " << numeroRodada << std::endl;
        exit( 1 );
    }
    
    Game* jogo;
    Equip* equipe;
    vector< Game* > jogos = rodadas.at( numeroRodada-1 )->getJogos();
    
    for (int i = 0; i < jogos.size(); i++) {
        jogo = jogos.at( i );
        for (int j = 0; j < equipes.size(); j++) {
            equipe = equipes.at( j );
            if( equipe->get_name() == jogo->get_home() ){
                equipe->set_result( jogo->get_home_goals(), jogo->get_visitor_goals() );
            }else if( equipe->get_name() == jogo->get_visitor() ){
                equipe->set_result( jogo->get_visitor_goals(), jogo->get_home_goals() );
            }
        }
    }
    
}
    
int Classificacao::getNumeroRodadas(){
    return rodadas.size();
}

void Classificacao::ordenar() {
    int valorA = 0, valorB = 0;
    for (int i = 0; i < equipes.size(); i++) {
        for (int j = i+1; j < equipes.size(); j++) {
            for (int k = 0; k < NUMERO_CRITERIOS_DESEMPATE; k++) {
                switch( criterios[ k ] ){
                    case PONTOS:
                        valorA = equipes.at( i )->get_points();
                        valorB = equipes.at( j )->get_points();
                        break;
                    
                    case SALDO_GOLS:
                        valorA = equipes.at( i )->get_diff_goals();
                        valorB = equipes.at( j )->get_diff_goals();
                        break;
                        
                    case GOLS_MARCADOS:
                        valorA = equipes.at( i )->get_pro_goals();
                        valorB = equipes.at( j )->get_pro_goals();
                        break;
                        
                    case VITORIAS:
                        valorA = equipes.at( i )->get_wins();
                        valorB = equipes.at( j )->get_wins();
                        break;
                }
                
                if( valorA < valorB ){
                    Equip* e = equipes.at( i );
                    equipes[ i ] = equipes[ j ]; 
                    equipes[ j ] = e;
                    break;
                }else if( valorA > valorB ){
                    break;
                }
            }
        }
    }

}

string Classificacao::mostrar(){
    int tamanho = equipes.size();
    
    if( tamanho == 0 ){
        return "Nenhuma equipe nesta classificação";
    }else{
        string s = "";
        for (int i = 0; i < tamanho; i++) {
            s += intParaString( i+1 ) + "º" + equipes.at(i)->to_latex() + '\n';
        }
        return s;
    }
}


string Classificacao::gerarClassificacaoArquivoLatex(){
    int tamanho = equipes.size();
    string s = "";
    for( int i = 0; i < tamanho; i++ ){
        s += intParaString( i+1 ) + "º" + equipes.at( i )->to_latex() + '\n';
    }
    s += "\n\n\n";
    return s;
}