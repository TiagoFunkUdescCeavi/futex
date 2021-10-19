#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "File.h"
#include "Messenger.h"

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
        throw runtime_error( Messenger::instance()->error_on_open_file( this->file_name ) );
    }
    
    arq << s << endl;
    
    arq.close();
}

vector< string > File::read(){
    char charAux;
    string str = "";
    vector< string > vector_str;
    ifstream arq;
    
    arq.open( this->file_name.c_str(), ios::in );
    
    if( !arq ){
        throw runtime_error( Messenger::instance()->error_on_open_file( this->file_name ) );
    }
    
    while( !arq.eof() ){
        charAux = arq.get();
        if( charAux == '\n' ){
            vector_str.push_back( str );
            str = "";
        }else{
            str += charAux;
        }
    }
    str = str.substr( 0, str.length() - 1);
    vector_str.push_back( str );
    
    arq.close();
    
    return vector_str;
}