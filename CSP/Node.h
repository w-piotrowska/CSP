#pragma once
#include <vector>
#include <string>
using namespace std;
class Node
{
public:
	Node();
	Node(int domain_size);
	Node(int domain_size, int xi, int yi);
	~Node();

	int getX();
	int getY();
	int getValue();
	bool setValue();
	bool deleteFromDomain(int val);
	bool addToDomain(int val);
	bool isDomainEmpty();
	void recreate(int domain_size);
	bool isInDomain(int val);

	string print();
	string printValueOnly();

private:
	int value;
	vector<int> domain;
	int x;
	int y;
};

