/*
 * Initilize_Board_Function.cpp
 *
 *  Created on: Apr 2, 2021
 *      Author: benxander
 */
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
void InitilizeBoard(char map[][8], int size, char name) {
	srand(time(NULL)); //randomizes with time.h library
	int ship_loc[2][size]; //location
	bool not_set = true; //makes sure ship is placed
	while (not_set) { //for when ship isn't placed
		not_set = false;
		bool orientation = (rand() % 2); //Randomizes orientation
		int i = rand() % 8, j = rand() % (8 - size + 1);
		for (int ii = 0; ii < size; ii++) { //vertical or horizontal
			if (orientation) {
				ship_loc[0][ii] = i;
				ship_loc[1][ii] = j + ii;
			} else {
				ship_loc[1][ii] = i;
				ship_loc[0][ii] = j + ii;
			}
			if (map[ship_loc[0][ii]][ship_loc[1][ii]] != ' ') { //checks if space taken
				not_set = true;
				break;
			}
		}
	}
	for (int ii = 0; ii < size; ii++) { //for ship size
		map[ship_loc[0][ii]][ship_loc[1][ii]] = name; //places ship
	}
}
//copied this code from Professor Li, previous code worked and was using the same method but was 20 more lines
