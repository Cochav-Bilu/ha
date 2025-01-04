#include "Bishop.h" 
#include "Tool.h"

// constructor of the bishop class, initializing location and player tool by calling the constructor of the base class Tool
Bishop::Bishop(int loc[2], int player) : Tool(loc, player) {}


// checks if the move from the current position to the destination is legal for the bishop
bool Bishop::isLegal(const int* dest, Board board) const
{
    // check if the move is diagonal (the difference in x and y coordinates must be equal)
    if (abs(location[0] - dest[0]) == abs(location[1] - dest[1])) {

        // check if the destination cell does not contain a piece of the same player
        if (board.colorInCell(dest) != this->playerTool) {

            // check if there are no pieces blocking the path
            if (!board.isInBetween(this->location, dest)) {
                return true; // move is legal
            }
        }
    }
    return false; // move is not legal
}


// returns the tool name (bishop) based on the player's color (upper case for white, lower case for black)
char Bishop::getToolName() const
{
    if (WHITE == this->playerTool) // if the player is white
    {
        return 'B'; // uppercase 'B' for white bishop
    }
    return 'b'; // lowercase 'b' for black bishop
}
