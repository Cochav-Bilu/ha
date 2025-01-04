#include "Knight.h"

// constructor for the Knight class, calls the constructor of the base class Tool to initialize location and player tool
Knight::Knight(int loc[2], int player) : Tool(loc, player) {}

// checks if the move from the current position to the destination is legal for the knight
// knight moves in an 'L' shape: two squares in one direction and one square in a perpendicular direction
bool Knight::isLegal(const int* dest, Board board)const
{
    // calculate the difference in x and y coordinates
    int x = dest[0] - location[0];
    int y = dest[1] - location[1];

    // check if the move is valid: either move 1 in one direction and 2 in the other direction, or vice versa
    if ((y == 1 || y == -1) && (x == -2 || x == 2) || (y == 2 || y == -2) && (x == -1 || x == 1))
    {
        return true; // move is legal
    }
    return false; // move is not legal
}

// returns the tool name (knight) based on the player's color (upper case for white, lower case for black)
char Knight::getToolName() const
{
    if (WHITE == this->playerTool) // if the player is white
    {
        return 'N'; // uppercase 'N' for white knight
    }
    return 'n'; // lowercase 'n' for black knight
}
