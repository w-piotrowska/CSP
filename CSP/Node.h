#pragma once
#include <vector>
using namespace std;
class Node
{
public:
	Node();
	Node(int domain_size);
	~Node();

	int getValue();
	bool setValue();
	bool deleteFromDomain(int val);
	bool addToDomain(int val);
	bool isDomainEmpty();
	void recreate(int domain_size);

private:
	int value;
	vector<int> domain;
	int x;
	int y;
};

