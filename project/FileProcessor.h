#ifndef PROCESSADORARQUIVO_H
#define PROCESSADORARQUIVO_H

#include <string>
using std::string;

#include <map>
using std::map;
using std::less;

#include <exception>
using std::exception;

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
};

#endif
