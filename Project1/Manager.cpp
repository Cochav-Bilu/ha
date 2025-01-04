#include "Manager.h"
#include <iostream>

Manager::Manager()
{
    board = Board();  // initialize the board when the manager is created
}

Manager::~Manager()
{
    // destructor not needed for this class, as resources are managed by the board
}

char* Manager::move(int location[], int dst[])
{
    char retValue[2] = { '0', NULL };

    // check if the move is within the board bounds
    if (location[0] > MAX_SIZE || location[0] < 0 || dst[0] > MAX_SIZE || dst[0] < 0 || location[1] > MAX_SIZE || location[1] < 0 || dst[1] > MAX_SIZE || dst[1] < 0)
    {
        retValue[0] = INVALID_INDEX;  // return invalid index if out of bounds
    }
    // check if the location and destination are the same
    else if (location[0] == dst[0] && location[1] == dst[1])
    {
        retValue[0] = DIDNT_MOVE;  // no move made
    }
    // check if the target place has the color of the player
    else if (board.colorInCell(dst) == board.playerTurn)
    {
        retValue[0] = YOUR_TOOL_IN_DEST;  // can't move to a square with your own piece
    }
    else  // valid move so far
    {
        Tool* t = board.boardArr[location[0]][location[1]];  // get the piece to move

        if (!t)  // if the piece is NULL
        {
            retValue[0] = NOT_YOUR_TOOL;  // no piece to move
        }
        // check if the piece is not of the current player's color
        else if (t->getPlayerTool() != board.playerTurn)
        {
            retValue[0] = NOT_YOUR_TOOL;  // it's not the current player's piece
        }
        else
        {
            // save original state in case of self-check
            Tool* originalTool = board.boardArr[location[0]][location[1]];
            Tool* originalDestTool = board.boardArr[dst[0]][dst[1]];

            // make the move if it's legal
            if (t->isLegal(dst, board))
            {
                t->setNewLocation(dst);
                board.boardArr[dst[0]][dst[1]] = t;
                board.boardArr[location[0]][location[1]] = nullptr;

                // check if the move causes self-check
                if (board.isCheck())
                {
                    // revert to the original state if self-check occurs
                    board.boardArr[location[0]][location[1]] = originalTool;
                    board.boardArr[dst[0]][dst[1]] = nullptr;
                    t->setNewLocation(location);
                    retValue[0] = SALF_CHECK;  // self-check detected
                }
                else
                {
                    // delete the piece in the destination if there was one
                    if (originalDestTool != nullptr)
                    {
                        delete originalDestTool;
                    }
                    // change turn as the move was legal
                    board.playerTurn = 1 - board.playerTurn;

                    // check if the move caused a check on the opponent
                    if (board.isCheck())
                    {
                        retValue[0] = VALID_CHECK;  // valid move, but it puts the opponent in check
                    }
                    else
                    {
                        retValue[0] = VALID;  // valid move with no check
                    }
                }
            }
            else
            {
                retValue[0] = ILIGAL_MOVE;  // move is not legal for the piece
            }
        }
    }

    return retValue;  // return the result of the move attempt
}

void Manager::str2arr(int loc[2], int dst[2], std::string msg) const
{
    // convert the string representation of the move to an array of locations
    loc[0] = msg[0] - 'a' + 1;  // letter (a-h) to number (1-8)
    loc[1] = msg[1] - '0';      // char to number (1-8)

    dst[0] = msg[2] - 'a' + 1;  // letter (a-h) to number (1-8)
    dst[1] = msg[3] - '0';      // char to number (1-8)
}

void Manager::startMsg(char msg[66])
{
    int count = 0;
    char c = ' ';

    // create the starting message based on the board state
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            if (board.boardArr[i][j] != nullptr)
            {
                c = board.boardArr[i][j]->getToolName();  // get the tool's name
            }
            else
            {
                c = '#';  // empty cell
            }
            msg[count] = c;
            count++;
        }
    }

    msg[64] = '0';  // add end of string
    msg[65] = NULL;
}
