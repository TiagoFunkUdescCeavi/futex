#include <cstdlib>
#include <string>
#include <iostream>
#include <exception>

#include "StringProcessor.h"
#include "Phase.h"
#include "File.h"
#include "Messenger.h"
#include "Goal.h"

#include "FileProcessor.h"

FileProcessor::FileProcessor( string file_name ) {
    this->file_name = file_name;
    this->actual_line = 1;
}

Championship * FileProcessor::process() {
    File* f = new File( file_name );
    vector< string > vector_str = f->read();
    if( vector_str.empty() ) throw runtime_error( Messenger::instance()->file_is_empty( this->file_name) );

    for( unsigned int i = 0; i < vector_str.size(); i++ ){
        process_line( vector_str[ i ] );
    }
    
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

    }else if( command == GOAL ){
        this->process_goal( value );

    }else{
        throw runtime_error( Messenger::instance()->command_not_found( this->actual_line, command ) );
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
    this->actual_phase = new Phase( trim( value ) );
    this->championship->add_phase( this->actual_phase );
    std::cout << "Fase criada: " << value << std::endl;
}

void FileProcessor::process_round( string value ){
    this->actual_phase->create_new_round();
    this->actual_round = stoi( trim( value ) );
    std::cout << "Nova rodada: " << this->actual_round << std::endl;
}

void FileProcessor::process_game( string value ){
    vector< string > arguments = split( value, ' ' );
    string home = this->aliases[ arguments[ 0 ] ];
    string visitor = this->aliases[ arguments[ 1 ] ];
    this->actual_phase->insert_equip( new Equip( home ) );
    this->actual_phase->insert_equip( new Equip( visitor ) );
    this->actual_game = new Game( home, visitor, stoi( arguments[ 2 ] ), stoi( arguments[ 3 ] ) );
    this->actual_phase->insert_game( this->actual_round, this->actual_game );
    std::cout << "Jogo adicionado: " << this->actual_game->to_string() << std::endl;
}

void FileProcessor::process_goal( string value ){
    vector< string > arguments = split( value, ' ' );
    string name = arguments[ 0 ];
    string time = arguments[ 1 ];
    bool home = arguments[ 2 ] == "h";
    bool penalty = false;
    bool own_goal = false;
    if( arguments.size() == 4 ){
        if( arguments[ 3 ] == "p" ){
            penalty = true;
        }else if( arguments[ 3 ] == "c" ){
            own_goal = true;
        }
    }
    Goal * g = new Goal( name, time, penalty, own_goal );
    if( home ){
        this->actual_game->set_home_goal( g );
    }else{
        this->actual_game->set_visitor_goal( g );
    }
    std::cout << "Gol adicionado: " << g->to_string() << std::endl;
}

string * FileProcessor::split_command( string command ){
    string * split = new string[2];
    if( command.find( ":" ) == string::npos ){
        throw runtime_error( Messenger::instance()->token_not_found( this->actual_line, command ) );
    }else{
        split[ 0 ] = trim( command.substr( 0, command.find( ':', 0 ) ) );
        split[ 1 ] = trim( command.substr( command.find( ":" ) + 1 ) );
    }
    return split;
}