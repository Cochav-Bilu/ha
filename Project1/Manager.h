#pragma once
#include "Board.h"
#include "Pipe.h"
#include <string>

// error codes
#define VALID '0'                // move  valid
#define VALID_CHECK '1'          // move ->check for the opponent
#define NOT_YOUR_TOOL '2'        // the piece at the location doesnt belong to the  player
#define YOUR_TOOL_IN_DEST '3'    // the destination contains a piece from the same player
#define SALF_CHECK '4'           // move results in the player’s king being in check
#define INVALID_INDEX '5'        // the location or destination index is out of bounds
#define ILIGAL_MOVE '6'          // the move is not allowed for the given piece
#define DIDNT_MOVE '7'           // no move was made

class Manager
{
private:
    Board board;  // represents the chessboard

public:
    Manager();  // constructor to initialize the manager object, sets up the board
    ~Manager(); // destructor to clean up any resources

    // function that makes a move on the board, returns a string with the status code
    char* move(int location[], int dst[]);

    // helper function to convert a string message into two integer locations for a move
    void str2arr(int loc[2], int dst[2], std::string msg) const;

    // function to display the start message to the user
    void startMsg(char msg[66]);
};
