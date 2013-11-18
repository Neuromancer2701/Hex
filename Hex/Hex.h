/*
 * Hex.h
 *
 *  Created on: Nov 16, 2013
 *      Author: count zero
 */

#ifndef HEX_H_
#define HEX_H_

#include "Graph.h"
#include <sstream>
using std::stringstream;


class Hex {
	public:
		Hex();
		virtual ~Hex();

		void DrawGraph();
		bool Winner();
		void ReadInputs();
		stringstream hex_board;
		Graph board;
		stringstream fill_line;
		State winner;

	private:

		vector<char> direction_characters;
		vector<char> state_characters;




};

#endif /* HEX_H_ */
