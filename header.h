/*
 * header.h
 *
 *  Created on: Apr 2, 2021
 *      Author: benxander
 */

#ifndef HEADER_H_
#define HEADER_H_
void InitilizeBoard(char main_array[8][8]);
void DisplayBoard(char user_array[8][8]);
void AlreadyGuessed(char user_array[8][8], int, int);
void Miss(char main_array[8][8], char user_array[8][8], int, int);
void Hit(char main_array[8][8], char user_array[8][8], int, int, int&, int&,
		int&, int&, int&, int&);
void InitilizeBoard(char[][8], int, char);
#endif /* HEADER_H_ */
