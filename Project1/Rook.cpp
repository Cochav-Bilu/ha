#include "Rook.h"

Rook::Rook(int loc[2], int player) : Tool(loc, player) {}

// each tool checks for himself if the moving from his current location to the new location is legal
// in this case, checks if the move is straight (either horizontal or vertical) and if there are no pieces blocking the path
bool Rook::isLegal(const int* dest, Board board)const
{
    // check if the move is either horizontal (same row) or vertical (same column)
    if (location[1] == dest[1] || location[0] == dest[0]) // moved straight
    {
        // check if there are no pieces in between the current position and the destination
        if (!(board.isInBetween(this->location, dest))) // no pieces blocking the path
        {
            return true; // move is legal
        }
    }
    return false; // move is not legal
}

// returns the tool name (rook) based on the player's color (upper case for white, lower case for black)
char Rook::getToolName() const
{
    if (WHITE == this->playerTool) // if the player is white
    {
        return 'R'; // uppercase 'R' for white rook
    }
    return 'r'; // lowercase 'r' for black rook
}
