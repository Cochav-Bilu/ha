#include "Queen.h"

// constructor for the Queen class, initializing location and player tool by calling the constructor of the base class Tool
Queen::Queen(int loc[2], int player) : Tool(loc, player) {}

// each tool checks for himself if the moving from his current location to the new location is legal
// in this case, moves straight or diagonal
bool Queen::isLegal(const int* dest, Board board)const
{
    // check if the move is straight (same x or y coordinate) or diagonal (difference in x equals difference in y)
    if ((location[1] == dest[1] || location[0] == dest[0]) || ((dest[1] - location[1]) == dest[0] - (location[0])))
    {
        // check if there are no pieces blocking the path
        if (!(board.isInBetween(this->location, dest)))
        {
            return true; // move is legal
        }
    }
    return false; // move is not legal
}

// returns the tool name (queen) based on the player's color (upper case for white, lower case for black)
char Queen::getToolName() const
{
    if (WHITE == this->playerTool) // if the player is white
    {
        return 'Q'; // uppercase 'Q' for white queen
    }
    return 'q'; // lowercase 'q' for black queen
}
