/******************************************************************************
File Name: horseRace.cpp
Author: Teagan Holmes
Version: 1.1
Date Created: 1/22/24
Last Updated: 1/28/24
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getHorses() {
    int horses;
    while (true) { //while loop allows it to keep asking until condition is met // if horses < 2 is true, keep asking
        cout << "Enter the number of horses: ";
        cin >> horses;
        if (horses < 2) { //at least 2 horses
            cout << "Bare minimum is 2 horses. How can one horse race itself silly?! " << endl;
        } else {
            break; //release user from constant questioning!
        }
    }
    return horses; //return number of horses to be used later
}

int getTrackLength(){ //same as getHorses
    int trackLength;
    while (true){
        cout << "Enter the track length: ";
        cin >> trackLength;
        if (trackLength < 2) {
            cout << "Cmon now.. you know the drill... Track length must be at least 2..."<< endl; //user act right challenge..
        } else {
            break;
        }
    }
    return trackLength; //track length we got it!!
}

void
initializeRace (int numHorses, int *position) 
{
  for (int i = 0; i < numHorses; ++i)
    {
      position[i] = 0;		// start ur engines!! (horses all start at 0)
    }
}

void moveHorses(int numHorses, int *position) {
    int horseMoving = rand() % numHorses; // one random horse is chosen to move 
    //use rand % x, only picks a number that is in the scope of numHorses
    position[horseMoving] += 1; // move horse by one
}

void
displayRace (int numHorses, int *position)
{
  cout << endl;		//spaces out each time the race is printed, looks better
  for (int i = 0; i < numHorses; ++i) //loop through horses
    {
      cout << "Horse " << i + 1 << ": "; //print horse and its index +1 so no "Horse 0: "
      for (int j = 0; j < position[i]; ++j) //moving horse 
	{
	  cout << "."; //shows progress of horse
	}
      cout<<i+1<< endl; // for visualization purposes
    }
}

int
determineWinner (int numHorses, int *positions, int trackLength) //what horse and what position --> points to position + tracklength from input
{
  int winner = 0; 
  for (int i = 1; i < numHorses; ++i)
    {
      if (positions[i] == trackLength) //must have reached track length
	{
	  winner = i; // == trackLength == winner
	  break; //break out of loop once you find winner
	}
    }
  return winner; //says winner
}

int
main ()
{
  srand (time (0)); //randomize using time
  
  int trackLength = getTrackLength(); //store input
  
  int numHorses= getHorses(); //store input

  int horsePositions[numHorses]; // size = horses = how many positions there are

  initializeRace (numHorses, horsePositions); //start the race

  while (true) //keeps going until theres a winner
    {
      moveHorses (numHorses, horsePositions); //move
      displayRace (numHorses, horsePositions); //show

      int winner = determineWinner (numHorses, horsePositions, trackLength);
      if (winner != 0) //cannot win without movin'
	{
	  cout << "Horse " << winner + 1 << " wins the race!" << endl; //plus 1 again here, no "Horse 0 : "
	  break;
	}
    }
  return 0;
}
