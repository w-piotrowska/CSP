#pragma once
class NQueens
{
public:
	NQueens();
	~NQueens();

	bool check(int x, int y);
	void deleteValuesFromDomiein();

	void runBT();
	void runFC();
};

