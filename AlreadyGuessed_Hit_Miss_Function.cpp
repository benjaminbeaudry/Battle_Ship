/*
 * Hit_Function.cpp
 *
 *  Created on: Apr 2, 2021
 *      Author: benxander
 */
#include <iostream>
using namespace std;
#include <iomanip>
void AlreadyGuessed(char user_array[8][8], int user_r, int user_column) { //checks if space already guessed
	if (user_array[user_r][user_column - 1] != ' ') {
		cout << setw(34) << setfill('*') << "*" << endl;
		cout << "**\t   ALREADY GUESSED\t**" << endl;
		cout << setw(34) << setfill('*') << "*" << endl;
		system("PAUSE"); //pause game
		system("CLS"); //clear display
	}
}

void Hit(char main_array[8][8], char user_array[8][8], int user_r,
		int user_column, int &hit, int &aircraft_carrier, int &battleship,
		int &crusier, int &destroyer, int &submarine) { //checks if hit, marks space as "H" and announces if a ship is sunk
	if ((main_array[user_r][user_column - 1] != ' ')
			&& (user_array[user_r][user_column - 1] == ' ')) {
		cout << setw(34) << setfill('*') << "*" << endl;
		cout << "**\t\tHIT\t\t**" << endl;
		hit++; //used to end the game
		user_array[user_r][user_column - 1] = 'H';
		switch (main_array[user_r][user_column - 1]) {
		case 'D':
			destroyer++; //counts destroyer hits
			break;
		case 'S':
			submarine++; //counts submarine hits
			break;
		case 'C':
			crusier++; //counts cruiser hits
			break;
		case 'B':
			battleship++; //counts battleship hits
			break;
		case 'A':
			aircraft_carrier++; //counts aircraft carrier hits
			break;
		}
		if (destroyer == 2) { //if destroyer is destroyed display out ship sunk
			destroyer++;
			cout << "**     YOU SANK MY DESTROYER\t**" << endl;
		}
		if (submarine == 3) { //if submarine is destroyed display out ship sunk
			submarine++;
			cout << "**     YOU SANK MY SUBMARINE\t**" << endl;
		}
		if (crusier == 3) { //if cruiser is destroyed display out ship sunk
			crusier++;
			cout << "**\tYOU SANK MY CRUSIER\t**" << endl;
		}
		if (battleship == 4) { //if battleship is destroyed display out ship sunk
			battleship++;
			cout << "**    YOU SANK MY BATTLESHIP\t**" << endl;
		}
		if (aircraft_carrier == 5) { //if aircraft carrier is destroyed display out ship sunk
			aircraft_carrier++;
			cout << "** YOU SANK MY AIRCRAFT CARRIER\t**" << endl;
		}
		cout << setw(34) << setfill('*') << "*" << endl;
		system("PAUSE"); //pause game
		system("CLS"); //clear display
	}
}
void Miss(char main_array[8][8], char user_array[8][8], int user_r, //check if miss, marks space as "M"
		int user_column) {
	if ((main_array[user_r][user_column - 1] == ' ')
			&& (user_array[user_r][user_column - 1] == ' ')) {
		cout << setw(34) << setfill('*') << "*" << endl;
		cout << "**\t\tMISS\t\t**" << endl;
		user_array[user_r][user_column - 1] = 'M';
		cout << setw(34) << setfill('*') << "*" << endl;
		system("PAUSE"); //pause game
		system("CLS"); //clear display
	}
}

