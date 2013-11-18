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
#include <algorithm>

using std::find;
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

// Is this a valid free node
bool  Graph::ValidNode(int x, int y)
{
	bool return_value = false;
	unsigned int node_name = x * size + y;

	if(node_name < nodes.size())
	{
		if(nodes[node_name].state == State::free)
		{
			return_value = true;
		}
	}

	return return_value;
}
// Set Node to occupied by state
void Graph::Move(State state, int x, int y)
{
	int node_name = x * size + y;
	nodes[node_name].state = state;
}

bool Graph::Player1Winner()
{
	bool return_value = false;

	vector<int> start_nodes;  //Top of the Hex board
	vector<int> end_nodes;	  //Bottom Of the Hex Board

	vector<int> tree;
	vector<Node> openlist;

	for(int i = 0; i < size; i++)
	{
		start_nodes.push_back(i);
		end_nodes.push_back((size * size) - (i+1));
	}

	for( auto i : start_nodes)
	{
		openlist.push_back(nodes[i]);
	}

	//Create a tree starting Top nodes Winner when tree includes a start node and end node.
	while(openlist.size() > 0)
	{
		if(openlist[0].state == State::X)
		{
			for( auto edge :openlist[0].Edges)
			{
				openlist.push_back(nodes[edge.destination]);
			}
			tree.push_back(openlist[0].name);
			openlist.erase(openlist.begin());
		}
		else
		{
			openlist.erase(openlist.begin());
		}

		for( auto end : end_nodes)
		{
			if(find(tree.begin(), tree.end(), end) != tree.end() )
			{
				return_value = true;
			}
		}
	}
	return return_value;
}

bool Graph::Player2Winner()
{
	bool return_value = false;
	vector<int> start_nodes;  	//Left of the Hex board
	vector<int> end_nodes;	  	//Right Of the Hex Board

	vector<int> tree;			// Path to victor
	vector<Node> openlist;		//List of Nodes connected to a

	for(int i = 0; i < size; i++)
	{
		start_nodes.push_back(i * size );
		end_nodes.push_back((i * size) + size);
	}

	for( auto i : start_nodes)
	{
		openlist.push_back(nodes[i]);
	}

	//Create a tree starting Top nodes Winner when tree includes a start node and end node.
	while(openlist.size() > 0)
	{
		if(openlist[0].state == State::O)
		{
			for( auto edge :openlist[0].Edges)
			{
				openlist.push_back(nodes[edge.destination]);
			}
			tree.push_back(openlist[0].name);
			openlist.erase(openlist.begin());
		}
		else
		{
			openlist.erase(openlist.begin());
		}

		for( auto end : end_nodes)
		{
			if(find(tree.begin(), tree.end(), end) != tree.end() )
			{
				return_value = true;
			}
		}
	}

	return return_value;
}
// Creates Edges for each Node
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
