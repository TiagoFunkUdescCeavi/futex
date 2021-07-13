#ifndef STRING_PROCESSOR_H
#define STRING_PROCESSOR_H

#include <string>
using std::string;

int count_acents( string s );
string ajust_size( int size, string s, bool pos );
string trim( string s );
string* split( string s, char separator );

#endif