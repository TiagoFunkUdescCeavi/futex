#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
#include <sstream>
#include <istream>
#include <ostream>

using std::string;
using std::ostream;
using std::istream;
using std::ostringstream;
using std::istringstream;

string intParaString(int i);
string doubleParaString(double d);
string floatParaString(float f);

int stringParaInt(string s);
double stringParaDouble(string s);
float stringParaFloat(string s);

#endif /* CONVERSOR_H */