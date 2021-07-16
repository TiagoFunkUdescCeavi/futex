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
    this->actual_line = 1;
}

Championship * FileProcessor::process() {
    char aux = ' ';
    string line = "", str = "";
    File* f = new File( file_name );
    
    str = f->read();
    if( str == "" ) throw runtime_error("Arquivo está vazio: " + file_name + "\n");

    for (unsigned int i = 0; i < str.length(); i++) {
        aux = str[ i ];
        if( aux == '\n' || i-1 == str.length() ){
            process_line( line );
            line = "";
            this->actual_line++;
        }else{
            line += aux;
        }
    }
    process_line( line );
    this->championship->add_phase( this->classification );
    
    return this->championship;
}

void FileProcessor::process_line( string line){
    if( line.empty() || line == "\n" || line.substr( 0, 2 ) == "//" ){
        return ;
    }

    string * sc = this->split_command( line );

    this->process_command( sc[ 0 ], sc[ 1 ] );
}

void FileProcessor::process_command( string command, string value ){
    if( command == NAME ){
        this->process_name( value );

    } else if( command == ALIAS ){
        this->process_alias( value );

    }else if( command == PHASE ){
        this->process_phase( value );
        
    }else if( command == ROUND ){
        this->process_round( value );

    }else if( command == GAME ){
        this->process_game( value );

    }else{
        throw runtime_error( "Linha " + std::to_string( this->actual_line ) + " - Comando não encontrado: " + command + "\n");
    }
}

void FileProcessor::process_name( string value ){
    this->championship = new Championship( trim( value ) );
    std::cout << "Nome adicionado: " << value << std::endl;
}

void FileProcessor::process_alias( string value ){
    string alias = value.substr( 0, value.find( " ", 0 ) );
    string name = value.substr( value.find( " ", 0 ) + 1 );
    this->aliases.insert( Map::value_type( alias, name ) );
    cout << "Alias adicionado: " << alias << " - " << name << endl;
}

void FileProcessor::process_phase( string value ){
    if( this->classification != NULL ){
        this->championship->add_phase( this->classification );
    }
    classification = new Classification( trim( value ) );
    std::cout << "Fase criada: " << value << std::endl;
}

void FileProcessor::process_round( string value ){
    this->classification->create_new_round();
    this->actual_round = stoi( trim( value ) );
    std::cout << "Nova rodada: " << this->actual_round << std::endl;
}

void FileProcessor::process_game( string value ){
    string* arguments = split( value, ' ' );
    string home = this->aliases[ arguments[ 0 ] ];
    string visitor = this->aliases[ arguments[ 1 ] ];
    this->classification->insert_equip( new Equip( home ) );
    this->classification->insert_equip( new Equip( visitor ) );
    Game* g = new Game( home, visitor, stoi( arguments[ 2 ] ), stoi( arguments[ 3 ] ) );
    this->classification->insert_game( this->actual_round, g );
    std::cout << "Jogo adicionado: " << g->to_string() << std::endl;
}

string * FileProcessor::split_command( string command ){
    string * split = new string[2];
    if( command.find( ":" ) == string::npos ){
        string str = "Linha " + std::to_string( this->actual_line );
        str += " - Token \':\' não foi encontrado: " + command + "\n";
        throw runtime_error( str );
    }else{
        split[ 0 ] = trim( command.substr( 0, command.find( ':', 0 ) ) );
        split[ 1 ] = trim( command.substr( command.find( ":" ) + 1 ) );
    }
    return split;
}