#include "Constants.h"

string Constants::get_table_header(){
    string str = "\\begin{center}\n";
    str += "\\begin{tabular}{| c | l | c | c | c | c | c | c | c | c | c | c |}\n";
    str += "\\multicolumn{12}{c}{\\textbf{Classificação ao término da rodada}}\\\\\n";
    str += "Pos.&Equipe&Pts&J&V&E&D&GP&GC&SG&PA&RES\\\\\n";;
    return str;
}

string Constants::get_table_footer(){
    string str = "\\end{tabular}\n\\end{center}\n";
    return str;
}

string Constants::get_section( string s, bool numerable ){
    string str = "\\section";
    if( !numerable ) str += "*";
    str += "{" + s + "}\n";
    return str;
}

string Constants::get_subsection( string s, bool numerable ){
    string str = "\\subsection";
    if( !numerable ) str += "*";
    str += "{" + s + "}\n";
    return str;
}

string Constants::get_portuguese_acents(){
    return "áéíóúâêôãç";
}