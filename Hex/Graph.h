/*
 * Graph.h
 *
 *  Created on: Oct 25, 2013
 *      Author: SK1033
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "Node.h"
#include <vector>
#include <set>
#include <string>
using std::vector;
using std::multiset;
using std::string;

class Graph {

private :
	void FillEdges(Node& node);
public	:
	Graph();
	virtual ~Graph();


	void GenerateGraph(int size);
	bool ValidNode(int x, int y);
	void Move(State state, int x, int y);
	int size;
	vector<Node>  nodes;  //vector of nodes

};


#endif /* GRAPH_H_ */
