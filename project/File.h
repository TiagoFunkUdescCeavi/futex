#ifndef FILE_H
#define FILE_H

#include <string>
using std::string;

class File {
public:
    File( string file_name );
    
    void write( string s, bool erase );
    string read();
    
private:
    string file_name;
};

#endif