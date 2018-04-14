#pragma once
#include "CSPProblem.h"
#include <stack>
using namespace std;
class CSPCalculate
{
public:
	CSPCalculate();
	~CSPCalculate();

	bool backTracking();
	bool forwardChcking();

private:
	CSPProblem typeOfProblem;
	stack<Node> stackOfNodes;
};

