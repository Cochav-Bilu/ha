#include "Pawn.h"
#include "Tool.h"

Pawn::Pawn(int loc[2], int player) : Tool(loc, player) {}

bool Pawn::isLegal(const int* dest, Board board) const
{
    int startX = this->location[0];
    int startY = this->location[1];
    int destX = dest[0];
    int destY = dest[1];
    int direction = (this->playerTool == 1) ? 1 : -1; // Direction depends on the player (1 or -1).

    // Standard forward move (1 step)
    if (destX == startX + direction && destY == startY && !board.colorInCell(dest))
    {
        return true;
    }

    // First move (2 steps forward)
    if ((this->playerTool == 0 && startX == 6) || (this->playerTool == 1 && startX == 1))
    {
        int tempLoc[2] = { startX + direction, startY };
        if (!board.colorInCell(tempLoc) && !board.colorInCell(dest))
        {
            return true;
        }
    }

    // Diagonal capture
    if (abs(destX - startX) == 1 && abs(destY - startY) == 1 && board.colorInCell(dest) != 0 && board.colorInCell(dest) != this->playerTool)
    {
        return true;
    }

    // En passant capture (if applicable)
    // You can add logic for en passant here if the board supports it.

    return false;
}

char Pawn::getToolName() const
{
    if (WHITE == this->playerTool)
    {
        return 'P';
    }
    return 'p';
}

