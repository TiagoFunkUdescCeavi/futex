#ifndef PROCESSADORARQUIVO_H
#define PROCESSADORARQUIVO_H

#include <string>
#include <map>
#include <exception>

using namespace std;

#include "Classification.h"

class FileProcessor {
public:
    FileProcessor( string file_name );
    
    Classification* process();

private:
    const string CHAMPIONSHIP = "campeonato";
    const string ROUND = "rodada";
    const string GAME = "jogo";
    const string ALIAS = "alias";
    
    int actual_round;
    string file_name;
    Classification* classification;
    
    typedef map< string, string > Map;
    Map aliases;
    
    void process_line( int line_number, string line );
    void process_alias( string value );
    void process_round( string value );
    void process_game( string value );
    void process_championship( string value );
};

#endif
