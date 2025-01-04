#pragma once
#include "Board.h"

class Board;

// tool class representing a piece on the chessboard
class Tool
{
protected:
    int playerTool;  // stores the player's piece color: 1 for white, 0 for black
    int* location;   // pointer to an array representing the piece's coordinates [x, y]

public:
    // constructor to initialize the tool with a location and player color
    Tool(int* loc, const int player);

    // virtual function to check if moving from the current location to the destination is legal
    virtual bool isLegal(const int* dest, Board board) const = 0;

    // virtual function to return the character representing the tool (e.g., 'P' for pawn)
    virtual char getToolName() const = 0;

    // getter for location of the tool
    int* getLocation() const;

    // getter for the playerTool (the color of the piece)
    int getPlayerTool() const;

    // setter to set a new location for the tool
    void setNewLocation(int* newLoc);
};
