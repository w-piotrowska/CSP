#pragma once
#include "Square.h"
#include "LatinSquare.h"
#include "ColoringGraph.h"
#include "NQueens.h"
#include <stack>
class CSPProblem
{
public:
	CSPProblem();
	CSPProblem(int type_of_problem, int size, int domain_size);
	~CSPProblem();

	bool backTracking(Node* act_node);

	void runBT();
	void runFC();

	string print();

private:
	LatinSquare latinSquare;
	ColoringGraph coloringGraph;
	NQueens nQueens;
	stack<Node*> stackOfNodes;
	int type;
};

