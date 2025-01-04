#pragma once
#include <iostream>
#include "Tool.h"
#include "Pawn.h"   
#include "Queen.h"    
#include "Bishop.h"  
#include "Knight.h"   
#include "Rook.h"
#include "King.h"    

#define WHITE 1
#define BLACK 0

#define MAX_SIZE 8

class tool;

class Board
{
public:

	// first turn is white (white = 1 | black  = 0)
	int playerTurn = 1;  // initializes white to start the game

	// the board is 8x8 matrix where each cell can hold a piece (Tool)
	Tool* boardArr[MAX_SIZE][MAX_SIZE];

	// to know where the kings are - pointers will change automatically when the king moves
	King* whiteKing = nullptr;  // pointer to the white king piece
	King* blackKing = nullptr;  // pointer to the black king piece

	// checks if the current player is in check
	bool isCheck();  // returns true if the current player is in check

	// checks if there are any tools between the source and destination positions (diagonal and straight moves)
	bool isInBetween(int location[], const int dst[]);  // checks if there's a piece blocking the path

	// returns the current player's turn (1 for white, 0 for black)
	int getPlayerTurn() const;  // returns the current player's turn

	// Constructor to initialize an empty chess board
	Board();  // sets up the board with the initial configuration of pieces

	// Destructor to clean up the memory (deletes the pieces)
	~Board();  // cleans up dynamically allocated memory for pieces

	// prints the current state of the chess board
	void printBoard() const;  // prints the board with all the pieces in their positions

	// returns the color of the piece at a given location (1 for white, 0 for black, and other values for no piece)
	int colorInCell(const int location[]);  // returns the color of the piece at a given location

};
