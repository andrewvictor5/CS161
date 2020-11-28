/****************************************************************************************************************************************************************************************
** Program Filename: Homework Assignment 6
** Author: Andrew Victor
** Date: March 13th, 2018
** Description: A functional game of Checkers
****************************************************************************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cstdlib>

using namespace std;

char **init_board(int, int);
char make_board(char**, int, int);
void delete_board(char**, int);
void fill_board();
char *get_move(char**, char*);
void convert_cord(char*&);
int get_x(char*);
bool valid_input(char*);
bool valid_move(char**, char*);
void findx(char**);
/****************************************************************************************************************************************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************************************************************************************************************/
int main(int argc, char **argv){
	char input[256];
	int a = 10;
	char ten = a;
	int b = 12;
	char twelve = b;
	if(argc != 2 || *argv[1] != '8' && *argv[1] != ten && *argv[1] != twelve) {
		while(valid_input(input) == false){
			cout << "Please provide a valid size for the board\nValid sizes are 8, 10, and 12" << endl;
		cin.getline(input, 256);
		}
	if(valid_input(input) == true){
		int rows = atoi(input) +1;
		int cols = atoi(input) +1;
		char **board = init_board(rows, cols);
		make_board(board, rows, cols);
		char move[256];
		get_move(board, move);
		//valid_move(board, move);
		delete_board(board, rows);
	}
}
	if(*argv[1] == '8' || *argv[1] == ten || *argv[1] == twelve){
		int rows = atoi(argv[1])+1;
		int cols = atoi(argv[1])+1;
		char **board = init_board(rows, cols);
		make_board(board, rows, cols);
		char move[256];
		get_move(board, move);
		//valid_move(board, move);
		delete_board(board, rows);
		}

	return 0;
}
/****************************************************************************************************************************************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
****************************************************************************************************************************************************************************************/
bool valid_input(char *input){
	bool check;
	if(atoi(input) == 8 || atoi(input) == 10 || atoi(input) == 12)
		check = true;
	else
		return false;
	return check;
}
/****************************************************************************************************************************************************************************************
** Function: init_board
** Description: This function will initialize the game board based on the number of rows and columns selected by the user via commandline argument
** Parameters: int, int, int
** Pre-Conditions: Valid size of board
****************************************************************************************************************************************************************************************/
char **init_board(int rows, int cols){
	char **board = new char *[rows];
	for(int i=0; i<rows; i++){
		board[i] = new char[cols];
	}
	return board;
}
/****************************************************************************************************************************************************************************************
** Function: make_board
** Description: This function uses the sample code provided in the assignment to make a game board and print it out
** Parameters: void, int, int, int
** Pre-Conditions: board is valid size
****************************************************************************************************************************************************************************************/
char make_board(char** board, int rows, int cols){
	char piece = 32;
	for(int i=0; i<rows; i++){
		if (i>0 && i<(rows/2))
			piece = 120; //"x"
		else if (rows-i < rows/2)
			piece = 111; //"o"
		else
			piece = 32; // " "
		
		for(int j=0; j<cols; j++){
			if (i == 0) {
				char topRow = 64+j;
				if (j == 0)
					cout << "\033[30;41m " << " ";
				else
					cout << "\033[30;41m " << topRow;
			}
			else {
				if (j == 0 && i != 0) {
					if (i<10)
						cout << "\033[30;41m " << "0" << i;
					else
						cout << "\033[30;41m " << board[i][j] << i;
				}
				else if(i%2 == 0 && j%2 == 0)
					cout << "\033[30;47m " << board[i][j] << " ";
				else if(i%2 == 1 && j%2 ==1)
					cout << "\033[30;47m " << board[i][j] << " ";
				else { 
					board[i][j] = piece; 
					cout << "\33[0m " << board[i][j];
				}
			}
			cout << "\33[0m";
		}
		cout << endl;
	}
	return **board;
} 
/****************************************************************************************************************************************************************************************
** Function: get_move
** Description: This function will take in a c style string from the user to be their move
** Parameters: char, int
****************************************************************************************************************************************************************************************/
char *get_move(char **board, char *move){
	cout << "Please enter the coordinates of the piece you would like to move\nFollowed by the coordinates (without spaces)  of where you would like to move your piece \nExample: A4B3" << endl;
	//take in c style string of coordinates
	cin.getline(move, 256); //cin.clear(); cin.ignore();
	//cout << move << endl << strlen(move) << endl;;
	convert_cord(move);
	//for(int i=0; i<strlen(move); i++)
	//cout << move[i] << endl;
	return move;
}
/****************************************************************************************************************************************************************************************
** Function: convert_cord
** Description: This function will convert the move input string from the user from lettrs and nummbers to just numbers
** Parameters: void, char
****************************************************************************************************************************************************************************************/
void convert_cord(char* &move){
	char c;
	for(int i=0; i<4; i++){
		move[i] = toupper(move[i]);
		if(move[i] > 64 && move[i] < 91){
			move[i] = move[i] - 16;
		}
	}
	//cout << move << endl;
	return;
}
/****************************************************************************************************************************************************************************************
** Function: valid_move
** Description: This function will check to see if the user has selected a valid move
** Parameters: bool, char
****************************************************************************************************************************************************************************************/
bool valid_move(char **board, char *move){
	bool check;
	if(board[move[0]][move[1]] == 120 && board[move[2]][move[3]] == 32)
		check = true;
	else
		return false;
	//cout << check << endl;
	return check;
}
/****************************************************************************************************************************************************************************************
** Function: delete_board
** Description: This function will delete the memory allocated on the heap that was used to play the game
** Parameters: void, int, int
****************************************************************************************************************************************************************************************/
void delete_board(char** board, int rows){
	for(int i=0; i<rows; i++){
		delete[] board[i];
	}
	delete[] board;
}
/****************************************************************************************************************************************************************************************
** Function: delete_board
** Description: This function will delete the memory allocated on the heap that was used to play the game
** Parameters: int, board
****************************************************************************************************************************************************************************************/
void findx(char **board){
	char x = 'x';
	int xcount = 0;
	for(int i=0; board[i] != '\0'; i++){
		if(x == *board[i])
			xcount++;
	}
	cout << "Number of x's on the board:" << xcount << endl;
	return; 
}
