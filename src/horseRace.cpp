// Date Completed: 09/09/2022
// Program emulates a horse race of 5 horses that move across a race track 
// according to a coin flip until one horse reaches the end and is declared the winner

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#define END_OF_RACE 15

// function prototypes
int flipCoin();
void moveHorses();
void printTrack();
void checkWinner();

int horsesPosition[5] = {0, 0, 0, 0, 0};
bool keepGoing = true;

int main() {
  
  int input;
  std::cout << "Please enter a random seed: ";
  std::cin >> input;
  srand(time(NULL)); // Makes the program more random with time

// Runs the program as long as the keepGoing is true 
while (keepGoing)
  {
    moveHorses();
    printTrack();
	std::cin.ignore(); //User must press the enter key before the next track is printed 
    checkWinner();
  }
  
  return(0);
} //end main

// A random number between 0 and 1 is generated
int flipCoin() {

  int randomNumber = rand() % 2; 
  return randomNumber;
  
} //end flipCoin

void moveHorses() {

  // For loop represents the turns for the horse to flip a coin
  for (int i = 0; i < 5; i++)
  {
    int coin = flipCoin();

    // If coin is heads, then the horsePosition increments by 1
    if (coin == 1)
    {
      horsesPosition[i] = horsesPosition[i] + 1;
    }
    else {
      // do nothing
    }
  }
} //end moveHorses

// Using a nested for loop to create the track
void printTrack() {
  
  int i, j;
  
  for (i = 0; i < 5; i++)
  {

    for (j = 0; j < END_OF_RACE; j++)
    {

      // if horse's position is on the track(this is j) 
      // then print the horse's name
      // otherwise a dot will be printed
      if(horsesPosition[i] == j)
      {
        std::cout << i;
      }
      else
      {
        std::cout << ".";
      }   
    }
    std::cout << "\n";
  }
 std::cout << "\n";
  
} //end printTrack

void checkWinner() {

  // Check each winner for its position
  // if horse's position exceeds 15 then the race stops and winner is declared
  for(int i = 0; i < 5; i++)
    {
      if (horsesPosition[i] == END_OF_RACE)
        {
           keepGoing = false;
           std::cout << "Horse "<< i <<" wins!" << std::endl;
        }
    }
} //end checkWinner