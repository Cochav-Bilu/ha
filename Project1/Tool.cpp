#include "Tool.h"

//pure:
//each tool checks for himself if the moving from his curent location to the new location is legal
//bool isLegal(const int* dest)const = 0;

Tool::Tool(int* loc, const int player)
{
	location[0] = loc[0];
	location[1] = loc[1];
	playerTool = player;
}


//geters
int* Tool::getLocation()const
{
	return location;
}
int Tool::getPlayerTool()const
{
	return playerTool;
}

//seters
void Tool::setNewLocation(int* newLoc)
{
	location = newLoc;
}