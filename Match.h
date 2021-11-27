#ifndef MATCH_H
#define MATCH_H

#include "Game.h"
#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

class Match
{
  private:
    Game m_games[MAX_GAMES];
    float m_wins=0;
    int count =0;
    
  public:
    Match(){}
    //Pre: g is valid and declared
    //Post: None
    //Desc: prints out the win rate
    void final_results();
    //Pre: g is valid and declared
    //Post: None
    //Desc: plays the entire game as well as goes through the 5 turns
    void play(Game & g);
    //Pre: None
    //Post: int return type
    //Desc: Getter function for count
    int getCount() const{return count;}

};

#endif