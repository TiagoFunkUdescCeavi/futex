#ifndef EQUIP_H
#define EQUIP_H

#include <string>
using std::string;

class Equip {
public:
    Equip( string name );
    
    void set_result( int home_goals, int visitor_goals );
    
    void set_previous_position( int position );
    
    string get_name();
    int get_points();
    int get_games();
    int get_wins();
    int get_draws();
    int get_loses();
    int get_pro_goals();
    int get_sof_goals();
    int get_diff_goals();
    double get_aproveitamento();
    int get_previous_position();
    
    string to_string();
    string to_latex();
    
private:
    static const int NUMBER_PREVIOUS_RESULTS = 3;
    
    string name;
    int points;
    
    int games;
    int wins;
    int draws;
    int loses;
    
    int pro_goals;
    int sof_goals;
    int diff_goals;
    
    int aproveitamento;
    int previous_position;
    string previous_results[ NUMBER_PREVIOUS_RESULTS ];
    
};

#endif