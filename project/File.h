#ifndef FILE_H
#define FILE_H

#include <vector>
using std::vector;

#include <string>
using std::string;

class File {
public:
    File( string file_name );
    
    void write( string s, bool erase );
    vector< string > read();
    
private:
    string file_name;
};

#endif