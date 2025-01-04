#include "Tool.h"
#pragma once


class King : public Tool
{

public:

    // constructor for the King class, calls the constructor of the base class Tool to initialize location and player tool
    King(int loc[2], int player);

    // checks if the move from the current position to the destination is legal for the king
    // the king can move only one square in any direction, must not capture its own piece, and should not cause a self-check
    bool isLegal(const int* dest, Board board)const override;

    // returns the tool name (king) based on the player's color (upper case for white, lower case for black)
    char getToolName() const;
};
