#pragma once
#include "CSPProblem.h"
class LatinSquare : private CSPProblem
{
public:
	LatinSquare();
	~LatinSquare();

	bool check(int x, int y);
	void deleteValuesFromDomiein();

	void runBT();
	void runFC();
};

