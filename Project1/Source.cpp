/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Manager.h"

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));

	//conecting to front
	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	
	//creating the board
	Manager game = Manager();

	//creating the starter board msg
	char sMsg[66];
	game.startMsg(sMsg);


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	strcpy_s(msgToGraphics, sMsg); 
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		//translating the movment to fit the back
		int src[2], dst[2];
		game.str2arr(src, dst, msgFromGraphics);
		
		//making the move
		char* ans = game.move(src, dst);

		strcpy_s(msgToGraphics, ans); // msgToGraphics should contain the result of the operation

		///******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		///******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}