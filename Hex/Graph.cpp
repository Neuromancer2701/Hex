/*
 * Graph.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: SK1033
 */

#include "Graph.h"
#include <set>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::multiset;
using std::ifstream;


//blank constructor
Graph::Graph(){
	size = 0;
}

//
void Graph::GenerateGraph(int _size) {
	Node n;
	size = _size;
	n.name = 0;

	for(int x = 0; x < size; x++ )
	{
		for(int y = 0; y < size; y++ )
		{
			n.coords.first = x;
			n.coords.second = y;
			FillEdges(n);
			nodes.push_back(n);
			n.name++;
		}
	}
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
bool  Graph::ValidNode(int x, int y)
{
	bool return_value = false;
	int node_name = x * size + y;

	if(node_name < nodes.size())
	{
		if(nodes[node_name].state == State::free)
		{
			return_value = true;
		}
	}

	return return_value;
}

void Graph::Move(State state, int x, int y)
{
	int node_name = x * size + y;
	nodes[node_name].state = state;
}



void Graph::FillEdges(Node& node)
{
	Edge edge;
	vector<pair<int,int>> directions;
	directions.push_back(std::make_pair(-1, 1));
	directions.push_back(std::make_pair( 1,-1));
	directions.push_back(std::make_pair( 0, 1));
	directions.push_back(std::make_pair( 1, 0));
	directions.push_back(std::make_pair( 0,-1));
	directions.push_back(std::make_pair(-1, 0));


	for( auto d : directions)
	{
		int x = d.first  + node.coords.first;   //add direction to current node coo
		int y = d.second + node.coords.second;

		if((x < 0) || (y < 0) || (x == size) || (y == size)) //negative and size values are not valid
			continue;

		edge.source = node.name;
		edge.destination = x * size + y;
		edge.cost = 1.0;
	}
}