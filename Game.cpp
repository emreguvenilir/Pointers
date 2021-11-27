#include "Game.h"
#include <cmath>

using namespace std;


Game::Game(int citySize)
{
  m_citySize=citySize;
  m_arr = new string*[citySize];
  for(int i=0;i<citySize;i++)
  {
    m_arr[i] = new string[m_citySize];
  }
}

float Game::calcDistance(int x, int y,int love_x,int love_y)
{
    float ans = abs(sqrt(pow(x-love_x,2) + pow(y-love_y,2)));
    return ans;
}

ostream & operator << (ostream & out,Game & gameRHS)
{
  for(int a =0; a < gameRHS.m_citySize; a++)
  {
    out << "     " << a; 
  }
  out << endl; 

  for(int i =0; i< gameRHS.m_citySize; i++)
  { 
    out << i << " |  "; 
    for(int j = 0; j<gameRHS.m_citySize; j++)
    {
      if(j!=gameRHS.m_citySize-1)
      {
        out << gameRHS.m_arr[i][j] << "  ,  "; 
      }
      else
      {
        out << gameRHS.m_arr[i][j] << "  |";
      }
    }
    out << endl; 
  }
  out << endl << endl; 
  return out; 
}

void Game::reset()
{
  for(int i=0;i<m_citySize;i++)
  {
    for(int j=0;j<m_citySize;j++)
    {
        m_arr[i][j] = "";
    }
  }
}

void Game::setArray(const int x,const int y,const string s)
{
  m_arr[y][x] = s;
}

bool Game::results()
{
  if(m_score < m_rivalScore)
  {
    cout << "\nYou win! No Tinder today!" << endl;
    m_score = 0;
    m_rivalScore= 0;
    return true;
  }
  else if(m_score > m_rivalScore)
  {
    cout << "You lost! Hit up Tinder!" << endl;
    m_score = 0;
    m_rivalScore= 0;
    return false;
  }
  else
  {
    cout << "Threesome!!!" << endl;
    m_score = 0;
    m_rivalScore= 0;
    return true;
  }
}

Game::~Game()
{
  for(int i=0;i<m_citySize;i++)
  {
    //cout << i <<": segfault" << endl; 
    delete []m_arr[i];
  }
  delete []m_arr;
  m_arr = nullptr;
}
