// Date Completed: 09/09/2022
// Program has the same idea as the orginal horse race program, but includes some different features described below

// includes pointers to eliminate the need of a global array 
// the array in main() is passed as a parameter between each of the functions

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#define END_OF_RACE 15

// function prototypes
int rollDice();
void moveHorses(int horsesPosition[]);
void printTrack(int horsesPosition[]);
void checkWinner(int horsesPosition[]);

bool keepGoing = true;

int main() {
  
  int horsesPosition[5] = {0, 0, 0, 0, 0}; //pointers will access this array from memory
  int input;
  std::cout << "Please enter a random seed: ";
  std::cin >> input;
  srand(time(NULL));

// Runs the program as long as the keepGoing is true 
while (keepGoing)
  {
    moveHorses(horsesPosition); 
    printTrack(horsesPosition);
    std::cin.ignore(); // Asks the user to press the enter key in between printing tracks
    checkWinner(horsesPosition);
  }
  
  return(0);
} //end main

// creates a random number between 1-6 to be called
int rollDice() {

  int randomNumber = rand() % 6 + 1;
  return randomNumber;
  
} //end rollDice

void moveHorses(int horsesPosition[]) {

  // For loop represents the turns for the horse to roll a dice
  for (int i = 0; i < 5; i++)
  {
    int dice = rollDice();

    // If dice is even then the horsePosition increments by 2
    if ((dice % 2) == 0)
    {
      horsesPosition[i] += 2;
    }
	// Else dice is odd and the horse moves back 1 position
    else {
      horsesPosition[i] --;
    }
  }
} //end moveHorses

// Using a nested for loop to create the track
void printTrack(int horsesPosition[]) {
  
  int i, j;
  
  for (i = 0; i < 5; i++){

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

void checkWinner(int horsesPosition[]) {

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