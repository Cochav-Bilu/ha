#pragma once

#include "Tool.h"

class Rook : public Tool
{
public:
    // constructor for the Rook class, initializes location and player tool by calling the constructor of the base class Tool
    Rook(int loc[2], int player);

    // each tool checks for himself if the moving from his current location to the new location is legal
    // in this case, checks if the move is straight (either horizontal or vertical), doesn't capture a piece of the same color,
    // and there are no pieces in between
    bool isLegal(const int* dest, Board board)const override;

    // returns the tool name (rook) based on the player's color (upper case for white, lower case for black)
    char getToolName() const override;
};
