
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Game
{
  private:
    int m_citySize;
    string **m_arr;
    int m_rival_x;
    int m_rival_y;
    int m_love_x;
    int m_love_y;
    int m_x;
    int m_y;
    float m_score=0;
    float m_rivalScore=0;
    
  public:
    Game(){}
    Game(int citySize);
    ~Game();
    void reset();
    //Pre: None
    //Post: bool return type
    //Desc: Prints out results after 5 turns
    bool results();
    //Pre: out and gameRHS are valid
    //Post: return type ostream
    //Desc: extraction operator overload
    friend ostream & operator << (ostream & out, Game & gameRHS);
    //Pre: x,y,love_x,love_y is valid inputs > 0 and < 5
    //Post: return type float
    //Desc: returns the distance between (x,y) and (love_x,love_y)
    float calcDistance(int x,int y,int love_x,int love_y);
    //Pre: None
    //Post: float return type
    //Desc: returns the score of the player
    float getMScore() const {return m_score;}
    //Pre: None
    //Post: float return type
    //Desc: returns the score of the rival
    float getRScore() const {return m_rivalScore;}   
    //Pre: x, y, and s are all valid
    //Post: None
    //Desc: sets the point (x,y) in m_arr to string s
    void setArray(const int x,const int y,const string s);
    //Pre: score is valid
    //Post: None
    //Desc: setter for m_score
    void setScore(const float score){m_score += score;}
    //Pre: score is valid
    //Post: None
    //Desc: setter for m_rivalScore
    void setRScore(const float score){m_rivalScore += score;}
    //Pre: None
    //Post: int return type
    //Desc: returns the city size
    int getSize() const{return m_citySize;}
};

#endif
