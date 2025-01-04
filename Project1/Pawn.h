#include "Tool.h"
#pragma once

// here we need to remember that the pawn moves diagonally to capture but moves straight otherwise
// it is legal to move straight only if the square is empty
// it is legal to move diagonally only if there is an opponent's piece to capture
// if the pawn moves two squares forward from its initial position, this is allowed
class Pawn : public Tool
{
public:
    // constructor for the Pawn class, initializing location and player tool by calling the constructor of the base class Tool
    Pawn(int loc[2], int player);

    // each tool checks for himself if the moving from his current location to the new location is legal
    bool isLegal(const int* dest, Board board)const override;

    // returns the tool name (pawn) based on the player's color (upper case for white, lower case for black)
    char getToolName() const;
};
