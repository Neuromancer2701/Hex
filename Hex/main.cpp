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

	game.board.GenerateGraph(11);


	game.DrawGraph();
	game.ReadInputs();


	return 0;
}
