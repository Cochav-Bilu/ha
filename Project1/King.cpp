#include "King.h"

// constructor for the King class, calls the constructor of the base class Tool to initialize location and player tool
King::King(int loc[2], int player) : Tool(loc, player) {}

// checks if the move from the current position to the destination is legal for the king
// the king can move only one square in any direction
bool King::isLegal(const int* dest, Board board)const
{
    // calculate the move in x and y directions
    int xMove = location[0] - dest[0];
    int yMove = location[1] - dest[1];

    // check if the king moved one square in any direction (vertically, horizontally, or diagonally)
    if ((xMove == 0 || xMove == 1 || xMove == -1) && (yMove == 0 || yMove == 1 || yMove == -1)) {
        return true; // move is legal
    }
    return false; // move is not legal
}

// returns the tool name (king) based on the player's color (upper case for white, lower case for black)
char King::getToolName() const
{
    if (WHITE == this->playerTool) { // if the player is white
        return 'K'; // uppercase 'K' for white king
    }
    return 'k'; // lowercase 'k' for black king
}
