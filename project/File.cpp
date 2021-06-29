#include <cstdlib>

#include <fstream>

#include <iostream>

#include <string>

using namespace std;

#include "File.h"

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
        throw runtime_error("Erro ao abrir arquivo:" + this->file_name + "\n");
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
        throw runtime_error("Erro ao abrir arquivo:" + this->file_name + "\n");
    }
    
    while( !arq.eof() ){
        charAux = arq.get();
        str += charAux;
    }
    
    if( str.length() == 1 && charAux == -1 ){
        str = "";
    }else{
        str = str.substr( 0, str.length() - 2);
    }
    
    arq.close();
    
    return str;
}