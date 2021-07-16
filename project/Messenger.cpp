#include "Messenger.h"

Messenger * Messenger::_instance = 0;

Messenger::Messenger(){}

Messenger * Messenger::instance(){
    if( _instance == 0 ){
        _instance = new Messenger();
    }
    return _instance;
}

string Messenger::latex_file_header( string title ){
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

string Messenger::latex_file_footer(){
    string str = "\\end{document}\n";
    return str;
}

string Messenger::latex_table_header(){
    string str = "\\begin{center}\n";
    str += "\\begin{tabular}{| c | l | c | c | c | c | c | c | c | c | c | c | c |}\n";
    str += "\\multicolumn{13}{c}{\\textbf{Classificação ao término da rodada}}\\\\\n";
    str += "Pos.&Equipe&Pts&J&V&E&D&GP&GC&SG&PA&APROV&RES\\\\\n";;
    return str;
}

string Messenger::latex_table_footer(){
    string str = "\\end{tabular}\n\\end{center}\n";
    return str;
}

string Messenger::latex_section( string s, bool numerable ){
    string str = "\\section";
    if( !numerable ) str += "*";
    str += "{" + s + "}\n";
    return str;
}

string Messenger::latex_subsection( string s, bool numerable ){
    string str = "\\subsection";
    if( !numerable ) str += "*";
    str += "{" + s + "}\n";
    return str;
}

string Messenger::latex_comand( string file ){
    string s = file.substr( 0, file.find_last_of("/")+1 );
    string str = "pdflatex -synctex=1 -interaction=nonstopmode";
    str += " -shell-escape -output-directory=" + s + " " + file;
    str += ".tex > " + s + "pdflatex.log";
    return str;
}

string Messenger::portuguese_acents(){
    return "áéíóúâêôãç";
}

string Messenger::error_on_open_file( string file ){
    return "Erro ao abrir arquivo:" + file + ".\n";
}

string Messenger::file_is_empty( string file ){
    return "Arquivo está vazio: " + file + ".\n";
}

string Messenger::command_not_found( int line, string command ){
    return "Linha " + std::to_string( line ) + " - Comando não encontrado: " + command + ".\n";
}

string Messenger::token_not_found( int line, string command ){
    string str = "Linha " + std::to_string( line );
    str += " - Token \':\' não foi encontrado: " + command + ".\n";
    return str;
}

string Messenger::round_value_is_invalid( string cpp_file, int cpp_file_line, int round_value ){
    string str = cpp_file + ":";
    str += std::to_string( cpp_file_line ) + ":";
    str += "Valor da variável \"rodada\" é inválido: " + std::to_string( round_value ) + ".\n";
    return str;
}

string Messenger::sort_criterion_not_found( string cpp_file, int cpp_file_line ){
    string str = cpp_file + ":";
    str += std::to_string( cpp_file_line ) + ":";
    str += "Critério de desempate não foi encontrado.\n";
    return str;
}

string Messenger::expected_input(){
    return "Entrada esperada: ./futex <input_file>";
}

string Messenger::phase_empty(){
    return "Nenhuma equipe nesta classificação";
}