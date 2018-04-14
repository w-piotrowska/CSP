#pragma once
#include "Square.h"
class CSPProblem
{
public:
	CSPProblem();
	~CSPProblem();

	bool check(int x, int y);
	void deleteValuesFromDomein(int val, int x, int y);


	Square square;
	int domain_size;

};

