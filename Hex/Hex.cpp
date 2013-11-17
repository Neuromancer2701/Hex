/*
 * Hex.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: count zero
 */

#include "Hex.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Hex::Hex() {
	// TODO Auto-generated constructor stub
	direction_characters.push_back('\\');
	direction_characters.push_back('/');
	direction_characters.push_back('_');
	direction_characters.push_back('_');
	direction_characters.push_back('/');
	direction_characters.push_back('\\');

	state_characters.push_back('.');
	state_characters.push_back('O');
	state_characters.push_back('X');

}

Hex::~Hex() {
	// TODO Auto-generated destructor stub
}
void Hex::ReadInputs()
{
	int x, y;

	cout << "Welcome to the game of Hex!!!!" << endl;
	cout << "Player 1 enter Coordinates for your move" << endl;
	while(true)
	{
		cin >> x;
		cin >> y;
		if(!board.ValidNode(x, y))
		{
			cout <<  "Not a Valid move, try again!" << endl;
		}
		else
		{
			board.Move(State::X,x,y);
			break;
		}
	}

	cout << "Player 2 enter Coordinates for your move" << endl;
	while(true)
	{
		cin >> x;
		cin >> y;
		if(!board.ValidNode(x, y))
		{
			cout <<  "Not a Valid move, try again!" << endl;
		}
		else
		{
			board.Move(State::O,x,y);
			break;
		}
	}
}

void Hex::DrawGraph()
{
	string spaces =  " ";
	vector<Node>::iterator node = board.nodes.begin();
	fill_line	<< " " ;

	for(int i = 0 ; i < board.size; i++)
	{
		fill_line	<< '\\' ;
		if(i != (board.size-1))
		{
			fill_line << "  " << '/';
		}
	}



	for(int i = 0; i < board.size; i++)
	{
		hex_board << spaces;
		for(int j = 0; j < board.size; j++)
		{

			hex_board << state_characters.at((int)(*node).state);
			if(j != (board.size - 1))
			{
				hex_board << " " << direction_characters[2] << " ";
			}
			else
			{
				hex_board  << endl;
			}
			++node;
		}


		if(i != (board.size - 1))
		{
			hex_board << spaces << fill_line.str() << endl;
		}
		spaces += " ";
	}

	cout << hex_board.str() << endl;
}
