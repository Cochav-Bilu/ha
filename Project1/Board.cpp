#include "Board.h"


Board::Board()
{
    // initializing rows for the black player's pieces
    int loc[2]; // temporary array for location

    loc[0] = 0; loc[1] = 0; boardArr[0][0] = new Rook(loc, 0); // rook
    loc[1] = 1; boardArr[0][1] = new Knight(loc, 0); // knight
    loc[1] = 2; boardArr[0][2] = new Bishop(loc, 0); // bishop
    loc[1] = 3; boardArr[0][3] = new Queen(loc, 0); // queen

    loc[1] = 4;
    blackKing = new King(loc, 0); // storing pointer to the black king
    boardArr[0][4] = blackKing; // positioning the black king

    loc[1] = 5; boardArr[0][5] = new Bishop(loc, 0); // bishop
    loc[1] = 6; boardArr[0][6] = new Knight(loc, 0); // knight
    loc[1] = 7; boardArr[0][7] = new Rook(loc, 0); // rook

    // initializing pawns for the black player
    for (int j = 0; j < MAX_SIZE; ++j)
    {
        loc[0] = 1; loc[1] = j;
        boardArr[1][j] = new Pawn(loc, 0); // pawn
    }

    // empty rows in the middle of the board (rows 2-5)
    for (int i = 2; i < 6; ++i)
    {
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            boardArr[i][j] = nullptr; // empty cells
        }
    }

    // initializing pawns for the white player
    for (int j = 0; j < MAX_SIZE; ++j)
    {
        loc[0] = 6; loc[1] = j;
        boardArr[6][j] = new Pawn(loc, 1); // pawn
    }

    // initializing rows for the white player's pieces
    loc[0] = 7; loc[1] = 0; boardArr[7][0] = new Rook(loc, 1); // rook
    loc[1] = 1; boardArr[7][1] = new Knight(loc, 1); // knight
    loc[1] = 2; boardArr[7][2] = new Bishop(loc, 1); // bishop
    loc[1] = 3; boardArr[7][3] = new Queen(loc, 1); // queen

    loc[1] = 4;
    whiteKing = new King(loc, 1); // storing pointer to the white king
    boardArr[7][4] = whiteKing; // positioning the white king

    loc[1] = 5; boardArr[7][5] = new Bishop(loc, 1); // bishop
    loc[1] = 6; boardArr[7][6] = new Knight(loc, 1); // knight
    loc[1] = 7; boardArr[7][7] = new Rook(loc, 1); // rook
}

Board::~Board()
{
    // deleting all pieces and cleaning up the board
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            if (boardArr[i][j])
            {
                delete boardArr[i][j]; // deleting the piece
                boardArr[i][j] = nullptr; // nullifying the pointer
            }
        }
    }
}


bool Board::isCheck()
{
    // getting the location of the current player's king
    int* kingLocation;

    if (playerTurn == WHITE) {
        kingLocation = whiteKing->getLocation(); // white king
    }
    else {
        kingLocation = blackKing->getLocation(); // black king
    }


    // checking if any enemy piece can reach the king
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            if (boardArr[i][j] != nullptr && boardArr[i][j]->getPlayerTool() != playerTurn) {
                if (boardArr[i][j]->isLegal(kingLocation, *this)) {
                    return true; // if piece can reach the king, it's check
                }
            }
        }
    }

    return false; // no check
}

bool Board::isInBetween(int location[], const int dst[])
{
    // calculating the movement direction (true is 1, false is 0...)
    int stepRow = (dst[0] > location[0]) - (dst[0] < location[0]);
    int stepCol = (dst[1] > location[1]) - (dst[1] < location[1]);

    // moving one step from the start to the destination according to the steps above
    int curRow = location[0] + stepRow;
    int curCol = location[1] + stepCol;

    // checking if there is any piece in between
    while (curRow != dst[0] || curCol != dst[1])
    {
        if (boardArr[curRow][curCol] != nullptr)
        {
            return true; // if piece exists in between, return true
        }
        curRow += stepRow;
        curCol += stepCol;
    }

    return false; // no piece in between
}

int Board::getPlayerTurn() const
{
    return playerTurn; // returning the current player's turn
}

//Tool* Board::getToolAt(int row, int col) const
//{
//    return boardArr[row][col]; // retrieving the piece at the specified location
//}

void Board::printBoard() const
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            if (boardArr[i][j] != nullptr)
            {
                // printing the character representing the piece type
                std::cout << boardArr[i][j]->getToolName() << " ";
            }
            else
            {
                std::cout << "# "; // printing empty cell
            }
        }
    }
}

int Board::colorInCell(const int location[])
{
    Tool* t = this->boardArr[location[0]][location[1]];
    if (t)
    {
        int x = t->getPlayerTool();
        return x; // white or black
    }
    return -1; // empty cell (represented by -1)
}
