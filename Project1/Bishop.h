#include "Tool.h"
#pragma once


class Bishop : public Tool
{
public:

    // constructor of the bishop class, initializing location and player tool
    Bishop(int loc[2], int player);

    // each tool checks for itself if the movement from its current location to the new location is legal
    bool isLegal(const int* dest, Board board) const override;

    // returns the name of the tool, specific to this subclass (bishop)
    char getToolName() const;


};
