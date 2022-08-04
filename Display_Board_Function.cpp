/*
 * Display_Board_Function.cpp
 *
 *  Created on: Apr 2, 2021
 *      Author: benxander
 */
#include <iostream>
using namespace std;
void DisplayBoard(char user_array[8][8]) { //displays board with user hits and misses
	char board[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	cout << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |" << endl;
	cout << "---+---+---+---+---+---+---+---+---+" << endl;
	for (int cnt = 0; cnt < 8; cnt++) {
		cout << " " << board[cnt] << " ";
		for (int cnt2 = 0; cnt2 < 8; cnt2++)
			cout << "| " << user_array[cnt][cnt2] << " ";
		cout << "|\n---+---+---+---+---+---+---+---+---+" << endl;
	}
}
