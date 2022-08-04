//============================================================================
// Name        : system.cpp
// Author      : Ben Beaudry
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "header.h"
const int ROW = 8; //global variable of row
const int COL = 8; //global variable of column
//Destroyer 2, Submarine 3, Battleship 4, Cruiser 3 and Aircraft Carrier 5.
const int NUMBER_SHIP = 5;
const int SHIP_SIZE[NUMBER_SHIP] = { 2, 3, 4, 3, 5 };
const int SHIP_NAME[NUMBER_SHIP] = { 'D', 'S', 'B', 'C', 'A' };

int main() {
	char main_array[ROW][COL];
	char user_array[ROW][COL];
	for (int i = 0; i < ROW; i++) {
		for (int ii = 0; ii < COL; ii++) {
			main_array[i][ii] = ' ';
			user_array[i][ii] = ' ';
		}
	}
	int user_column, user_r, hit = 0, aircraft_carrier = 0, battleship = 0,
			crusier = 0, destroyer = 0, submarine = 0; //Initializing all integer variables
	float efficiency, guess_count = 0; //Initializing all decimal variables
	char user_row, cheat; //initializing all character variables
	srand(time(NULL));
	for (int i = 0; i < 5; i++) { //places each ship
		InitilizeBoard(main_array, SHIP_SIZE[i], SHIP_NAME[i]);
	}
	cout << "do you want a cheat sheet? Y/N" << endl; //cheat board used for debugging
	cin >> cheat;
	do {
		if ((cheat == 'Y') || (cheat == 'y')) {
			DisplayBoard(main_array); //display cheat board function
			cout << endl;
		}
		DisplayBoard(user_array); //display user submission board function
		cout << "Enter Your Guess (Row {A-H} / Column {1-8})" << endl;
		cin >> user_row >> user_column; //Intakes user guess
		guess_count++; //counts guesses
		user_r = user_row - 65; //changes input from letter to number
		if ((user_r > 7) || (user_row < 0)) //checks for lower case
			user_r = user_row - 97;
		if ((user_r > 7) || (user_row < 0) || (user_column > 8)
				|| (user_column < 1)) {
			cout << "Format Error, Please Reenter" << endl; //if guess out of bounds reenter
			system("PAUSE");
			system("CLS");
			continue;
		}
		AlreadyGuessed(user_array, user_r, user_column); //function to check if space already guessed
		Miss(main_array, user_array, user_r, user_column); //function to check if miss
		Hit(main_array, user_array, user_r, user_column, hit, aircraft_carrier,
				battleship, crusier, destroyer, submarine); //function to check if hit, and counts ships sunk
	} while (hit < 17); //end game when all ships sunk

	DisplayBoard(user_array); //display final board
	efficiency = 17 / guess_count * 100; //calculate efficiency
	cout << setw(34) << setfill('*') << "*" << endl;
	cout << "** GAME OVER\t\t\t**" << endl; //end game text with guess count and efficiency
	cout << "** Guess Count      = " << guess_count << "\t**" << endl;
	cout << setprecision(3) << "** Guess Efficiency = " << efficiency << "%\t**"
			<< endl;
	cout << setw(34) << setfill('*') << "*" << endl;
	system("PAUSE"); //pause game before end
	return 0;
}
