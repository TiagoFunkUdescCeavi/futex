#include <cstdlib>
#include <string>
#include <iostream>
#include <exception>

#include "ProcessadorString.h"
#include "Classification.h"
#include "File.h"
#include "Conversor.h"

#include "FileProcessor.h"

using namespace std;

FileProcessor::FileProcessor( string file_name ) {
    this->file_name = file_name;
}

Classification* FileProcessor::process() {
    bool sucess = true;
    int line_number = 1;
    string line = "", str;
    File* f = new File( file_name );
    
    str = f->read();

    for (unsigned int i = 0; i < str.length(); i++) {
        if( str[ i ] == '\n' || i-1 == str.length() ){
            try{
                process_line( line_number, line );
            }catch ( exception &exception ){
                sucess = false;
            }
            line = "";
            line_number++;
        }else{
            line += str[ i ];
        }
    }
    try{
        process_line( line_number, line );
    }catch ( exception &exception ){
        sucess = false;
    }
    
    if( !sucess ){
        throw runtime_error( "DEVIDO AO ERRO DE SINTAXE, A GERAÇÃO DA TABELA FOI ABORTADO.\n");
    }
    
    return this->classification;
}

void FileProcessor::process_line( int line_number, string line){
    if( line.empty() || line == "\n" || line.substr( 0, 2 ) == "//" ){
        return ;
    }

    string comand, values;

    // 18446744073709551615
    // Valor para quando o find não encontra a ocorrência.
    if( line.find( ":" ) == 18446744073709551615 ){
        throw runtime_error("Linha " + std::to_string( line_number ) + " - Token \':\' não foi encontrado: " + line + "\n");
    }else{
        comand = trim( line.substr( 0, line.find( ':', 0 ) ) );
        values = trim( line.substr( line.find( ":" ) + 1 ) );
    }

    if( comand == "alias" ){
        string alias, name;
        alias = values.substr( 0, values.find( " ", 0 ) );
        name = values.substr( values.find( " ", 0 ) + 1 );
        
        aliases.insert( Map::value_type( alias, name ) );
        std::cout << "Alias adicionado: " << alias << " - " << name << std::endl;
        
    }else if( comand == "rodada" ){
        actual_round = stoi( trim( values ) );
        std::cout << "Nova rodada: " << actual_round << std::endl;
        
    }else if( comand == "jogo" ){
        int arguments_number = 0;
        string* arguments = separar( arguments_number, values, ' ' );
        Game* j = new Game( aliases[ arguments[ 0 ] ], aliases[ arguments[ 1 ] ], 
            stoi( arguments[ 2 ] ), stoi( arguments[ 3 ] ) );
        classification->insert_game( actual_round, j );
        std::cout << "Jogo adicionado: " << j->to_string() << std::endl;
        
    }else if( comand == "campeonato" ){
        classification = new Classification( stoi( trim( values ) ) );
        for( Map::const_iterator iter = aliases.begin(); iter != aliases.end(); iter++ ){
            classification->insert_equip( new Equip( iter->second ) );
        }
        std::cout << "Campenato criado: " << values << " rodadas" << std::endl;
        
    }else{
        throw runtime_error( "Linha " + std::to_string( line_number ) + " - Comando não encontrado: " + comand + "\n");
    }

}
