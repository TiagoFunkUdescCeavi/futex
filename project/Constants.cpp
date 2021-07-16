#include "Constants.h"

string Constants::get_latex_file_header( string title ){
    string str = "\\documentclass{article}\n";
    str += "\\usepackage[utf8]{inputenc}\n";
    str += "\\usepackage[T1]{fontenc}\n";
    str += "\\usepackage[brazil]{babel}\n";
    str += "\n";
    str += "\\setlength{\\parindent}{0cm}\n";
    str += "\n";
    str += "\\title{\\textbf{" + title + "}}\n";
    str += "\\author{}\n";
    str += "\\date{}\n";
    str += "\n";
    str += "\\begin{document}\n";
    str += "\\maketitle\n";
    return str;
}

string Constants::get_latex_file_footer(){
    string str = "\\end{document}\n";
    return str;
}

string Constants::get_table_header(){
    string str = "\\begin{center}\n";
    str += "\\begin{tabular}{| c | l | c | c | c | c | c | c | c | c | c | c | c |}\n";
    str += "\\multicolumn{13}{c}{\\textbf{Classificação ao término da rodada}}\\\\\n";
    str += "Pos.&Equipe&Pts&J&V&E&D&GP&GC&SG&PA&APROV&RES\\\\\n";;
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