#include "Match.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Header.h"

using namespace std;

void Match::final_results()
{
  float win_rate = m_wins /count;
  //cout << "\nwins: " << m_wins;
  //cout << "\ncount: " << count;
  cout << "\nPlayer Win Rate: " << (win_rate) << endl;
}

void Match::play(Game & g)
{
  for(int i=0;i<NUM_TURNS;i++)
  {
    int x,y,lX,lY,rX,rY;
    cout <<"\nTurn " << i+1<< endl;
    cout <<"\nPlayer Score: " << g.getMScore();
    cout <<"\nRival Score: " << g.getRScore();

    do
    {
      cout << "\nEnter x: ";
      cin>> x;
    } while (x<MIN_CORD || x >g.getSize()-1);
    do
    {
      cout << "\nEnter y: ";
      cin>> y;
    } while (y<MIN_CORD || y >g.getSize()-1);

    lX = (rand() % g.getSize());
    lY = (rand() % g.getSize());
    rX = (rand() % g.getSize());
    rY = (rand() % g.getSize());

    g.setArray(x,y,STR_PLAYER);
    g.setArray(lX,lY,STR_LOVE);
    g.setArray(rX,rY,STR_RIVAL);

    cout << g;
    
    g.reset();
    float dist,rivDist;
    dist = g.calcDistance(x,y,lX,lY);
    rivDist = g.calcDistance(rX,rY,lX,lY);

    cout << "\nPlayer Distance to Love Interest: " << dist;
    cout << "\nRival Distance to Love Interest: " << rivDist;
    if(dist < rivDist)
    {
        cout << "\nPlayer wins this turn!";
    }
    else
    {
        cout << "\nRival wins this turn!";
    }
    g.setScore(dist);
    g.setRScore(rivDist);

    cout << endl;
  }
  bool win = g.results();
  if(win)
  {
    m_wins++;
  }
  m_games[count] = g;
  count++;
}



