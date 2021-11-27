#include <iostream>
#include <cmath>

#include "Game.h"
#include "Match.h"

using namespace std;

int main()
{ 
  srand(8);
  const int MAX_GAMES = 20;
  Match m;
  char playAgain;
  char newCity='y';
  int size;
  cout << "Welcome to the Love Triangle Game! Ready for some heartbreak? I am."<<endl;
  do
  {
    cout << "\nHow big is your city?: ";
    cin >> size;
  } while (size < 1);

  do
  {
    Game game1(size);
    cout << game1;
    m.play(game1);

    do
    {
      cout << "\nDo you want to continue playing (y/n)?: ";
      cin>> playAgain;
    } while (playAgain != 'y' && playAgain != 'n');
    
    if(playAgain== 'y')
    {
      do
      {
        cout << "\nDo you want to start in a new city (y/n)?: ";
        cin>> newCity;
      } while (newCity != 'y' && newCity != 'n');
      if(newCity=='y')
      {
        do
        {
          cout << "\nHow big is the size of the new city?: ";
          cin >> size;
        } while (size < 1);
      }
    }
    
  }while(playAgain=='y' && (m.getCount() < MAX_GAMES));

  
  m.final_results();
}