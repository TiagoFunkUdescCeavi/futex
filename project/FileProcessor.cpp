#include <cstdlib>
#include <string>
#include <iostream>
#include <exception>

#include "StringProcessor.h"
#include "Classification.h"
#include "File.h"

#include "FileProcessor.h"

FileProcessor::FileProcessor( string file_name ) {
    this->file_name = file_name;
}

Classification* FileProcessor::process() {
    char aux = ' ';
    int line_number = 1;
    string line = "", str = "";
    File* f = new File( file_name );
    
    str = f->read();

    for (unsigned int i = 0; i < str.length(); i++) {
        aux = str[ i ];
        if( aux == '\n' || i-1 == str.length() ){
            process_line( line_number, line );
            line = "";
            line_number++;
        }else{
            line += aux;
        }
    }
    process_line( line_number, line );
    
    return this->classification;
}

void FileProcessor::process_line( int line_number, string line){
    if( line.empty() || line == "\n" || line.substr( 0, 2 ) == "//" ){
        return ;
    }

    string comand, value;
    if( line.find( ":" ) == string::npos ){
        throw runtime_error("Linha " + std::to_string( line_number ) + " - Token \':\' não foi encontrado: " + line + "\n");
    }else{
        comand = trim( line.substr( 0, line.find( ':', 0 ) ) );
        value = trim( line.substr( line.find( ":" ) + 1 ) );
    }

    if( comand == ALIAS ){
        this->process_alias( value );
        
    }else if( comand == ROUND ){
        this->process_round( value );

    }else if( comand == GAME ){
        this->process_game( value );

    }else if( comand == CHAMPIONSHIP ){
        this->process_championship( value );

    }else{
        throw runtime_error( "Linha " + std::to_string( line_number ) + " - Comando não encontrado: " + comand + "\n");
    }

}

void FileProcessor::process_alias( string value ){
    string alias, name;
    alias = value.substr( 0, value.find( " ", 0 ) );
    name = value.substr( value.find( " ", 0 ) + 1 );
    aliases.insert( Map::value_type( alias, name ) );
    cout << "Alias adicionado: " << alias << " - " << name << endl;
}

void FileProcessor::process_round( string value ){
    this->actual_round = stoi( trim( value ) );
    std::cout << "Nova rodada: " << this->actual_round << std::endl;
}

void FileProcessor::process_game( string value ){
    string* arguments = split( value, ' ' );
    Game* g = new Game(
        this->aliases[ arguments[ 0 ] ], this->aliases[ arguments[ 1 ] ], 
        stoi( arguments[ 2 ] ), stoi( arguments[ 3 ] )
    );
    classification->insert_game( this->actual_round, g );
    std::cout << "Jogo adicionado: " << g->to_string() << std::endl;
}

void FileProcessor::process_championship( string value ){
    classification = new Classification( stoi( trim( value ) ) );
    for( Map::const_iterator iter = aliases.begin(); iter != aliases.end(); iter++ ){
        classification->insert_equip( new Equip( iter->second ) );
    }
    std::cout << "Campeonato criado: " << value << " rodadas" << std::endl;
}