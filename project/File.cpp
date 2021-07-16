#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "File.h"
#include "Constants.h"

File::File(string file_name) {
    this->file_name = file_name;
}

void File::write(string s, bool erase ){
    ofstream arq;
    
    if( erase ){
        arq.open( this->file_name.c_str(), ios::out );
    }else{
        arq.open( this->file_name.c_str(), ios::app );
    }
    
    if( !arq ){
        throw runtime_error( Constants::instance()->error_on_open_file( this->file_name ) );
    }
    
    arq << s << endl;
    
    arq.close();
}

string File::read(){
    char charAux;
    string str = "";
    ifstream arq;
    
    arq.open( this->file_name.c_str(), ios::in );
    
    if( !arq ){
        throw runtime_error( Constants::instance()->error_on_open_file( this->file_name ) );
    }
    
    while( !arq.eof() ){
        charAux = arq.get();
        str += charAux;
    }
    
    str = str.substr( 0, str.length() - 1);
    arq.close();
    
    return str;
}