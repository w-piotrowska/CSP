#pragma once
#include "Square.h"
class ColoringGraph
{
public:
	ColoringGraph();
	ColoringGraph(int size);
	~ColoringGraph();

	bool check(Node *node);
	void deleteValuesFromDomiein();

	Square square;
	int domain_size;
	stack<Node*> stackOfNodes;
};

