#include "Tool.h"
#pragma once

class Queen : public Tool
{

public:

    // constructor for the Queen class, initializing location and player tool by calling the constructor of the base class Tool
    Queen(int loc[2], int player);

    // each tool checks for himself if the moving from his current location to the new location is legal
    // in this case, moves straight or diagonal
    bool isLegal(const int* dest, Board board)const override;

    // returns the tool name (queen) based on the player's color (upper case for white, lower case for black)
    char getToolName() const override;

};
