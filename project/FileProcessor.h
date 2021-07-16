#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>
#include <map>
#include <exception>

using namespace std;

#include "Phase.h"
#include "Championship.h"

class FileProcessor {
public:
    FileProcessor( string file_name );
    
    Championship * process();

private:
    const string NAME = "nome";
    const string PHASE = "fase";
    const string ROUND = "rodada";
    const string GAME = "jogo";
    const string ALIAS = "alias";
    
    int actual_line;
    int actual_round;
    string file_name;
    Championship * championship;
    Phase* classification;
    
    typedef map< string, string > Map;
    Map aliases;
    
    void process_line( string line );
    void process_command( string command, string value );
    void process_name( string value );
    void process_alias( string value );
    void process_phase( string value );
    void process_round( string value );
    void process_game( string value );


    string * split_command( string command );
};

#endif
