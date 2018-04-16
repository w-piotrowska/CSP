#include "stdafx.h"
#include "CSPProblem.h"


CSPProblem::CSPProblem()
{
}

CSPProblem::CSPProblem(int type_of_problem, int size, int domain_size)
{
	type = type_of_problem;
	switch (type) {
	case 0:
		latinSquare = LatinSquare(size, domain_size);
		break;
	case 1:
		coloringGraph = ColoringGraph(size);
		break;
	case 2:
		nQueens = NQueens();
		break;
	}
}


CSPProblem::~CSPProblem()
{
}

bool CSPProblem::backTracking(Node * act_node)
{
	if (act_node == nullptr) {
		return true;
	}
	while (!act_node->isDomainEmpty()) {
		act_node->setValue();
		act_node->deleteFromDomain(act_node->getValue());
		switch (type) {
		case 0:
			if (latinSquare.check(act_node)) {
				stackOfNodes.push(act_node);
				if (latinSquare.square.selection() == NULL) return true;
				return backTracking(latinSquare.square.selection());
			}
			break;
		case 1:
			if (coloringGraph.check(act_node)) {
				stackOfNodes.push(act_node);
				if (coloringGraph.square.selection() == NULL) return true;
				return backTracking(coloringGraph.square.selection());
			}
			break;
		case 2:
			/*if (check(act_node)) {
				stackOfNodes.push(act_node);
				if (square.selection() == NULL) return true;
				return backTracking(square.selection());
			}*/
			break;
		}
	}
	switch (type) {
	case 0:
		act_node->recreate(latinSquare.domain_size);
		break;
	case 1:
		act_node->recreate(coloringGraph.domain_size);
		break;
	case 2:
		//act_node->recreate(nQueen.domain_size);
		break;
	}
	if (stackOfNodes.empty()) {
		return false;
	}
	else {
		Node *tmp = stackOfNodes.top();
		stackOfNodes.pop();
		return backTracking(tmp);
	}
}

void CSPProblem::runBT()
{
	switch (type) {
	case 0:
		backTracking(latinSquare.square.selection());
		break;
	case 1:
		backTracking(coloringGraph.square.selection());
		break;
	case 2:
		//backTracking(nQueen.square.selection());
		break;
	}
}

string CSPProblem::print()
{
	switch(type) {
	case 0:
		return latinSquare.square.print();
		break;
	case 1:
		return coloringGraph.square.print();
		break;
	case 2:
		//return nQueens.square.print();
		return "";
		break;
	}
	return "";
}
