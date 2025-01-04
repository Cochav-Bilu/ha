#include "Tool.h"
#pragma once

// Knight class inherits from Tool class
class Knight : public Tool
{

public:

    // constructor for the Knight class, calls the constructor of the base class Tool to initialize location and player tool
    Knight(int loc[2], int player);

    // checks if the move from the current position to the destination is legal for the knight
    // knight moves in an 'L' shape: two squares in one direction and one square in a perpendicular direction
    bool isLegal(const int* dest, Board board)const override;

    // returns the tool name (knight) based on the player's color (upper case for white, lower case for black)
    char getToolName() const override;

};
