#include <string>
using std::string;

#include <cstdlib>

#include "StringProcessor.h"
#include "Constants.h"

int count_acents( string s, string acents ){
    int count = 0;
    for( unsigned int i = 0; i < acents.size(); i += 2 ){
        if( s.find( acents.substr(i, 2) ) != string::npos ){
            count++;
        }
    }
    return count;
}

string ajust_size(int size, string s, bool pos ){
    int s_size = s.length() - count_acents( s, Constants::instance()->get_portuguese_acents() );
    if( size < s_size ){
        return s.substr( 0, size-1 );
    }
    for( int i = s_size; i < size; i++){
        if( pos ){
            s = s + " ";
        }else{
            s = " " + s;
        }
    }
    return s;
}

string trim( string s ){
    bool finded = false;
    int begin = 0, end = 0;
    int size = s.length();
    
    for( int i = 0; i < size; i++ ) {
        if( s[ i ] != ' ' ){
            begin = i;
            finded = true;
            break;
        }
    }
    if( !finded ){
        return "";
    }
    for( int i = size - 1; i >= 0; i-- ) {
        if( s[ i ] != ' ' ){
            end = i;
            break;
        }
    }
    
    return s.substr( begin, end-begin+1 );
}

string* split( string s, char separator ){
    int size = 0;
    char aux;
    string* vector = 0;
    
    s = trim( s );
    
    for( unsigned int i = 0; i <= ( s.length() - 1 ); i++) {
        aux = s[ i ];
        if( aux == separator ){
            size++;
        }
    }
    size++;
    vector = new string[ size ];
    
    int count = 0;
    int begin = 0;
    for( unsigned int i = 0; i <= ( s.length() - 1 ); i++) {
        aux = s[ i ];
        if( aux == separator ){
            vector[ count ] = s.substr( begin, i-begin );
            count++;
            begin = i + 1;
        }
    }
    vector[ count ] = s.substr( s.rfind( separator )+1 );
    
    return vector;
}