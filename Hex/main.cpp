//============================================================================
// Name        : Hex.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Hex.h"


int main() {

	Hex game;

	game.board.GenerateGraph(11); // Generate Graph of 11 by 11

	while(!game.Winner())		 // Test for Winner
	{
		game.DrawGraph();		// Draw Current Board
		game.ReadInputs();		//Read Inputs
	}

	if( game.winner == State::X)		//Player 1 won
		cout << "Congratulation Player 1, you Won!!" << endl;
	else if( game.winner == State::O)	//Player 2 won
		cout << "Congratulation Player 2, you Won!!" << endl;
	return 0;
}
