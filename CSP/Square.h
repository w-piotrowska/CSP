#pragma once
#include "Node.h"
class Square
{
public:
	Square();
	Square(int size, int domain_size);
	Square(const Square &pcOther);
	~Square();

	Square operator= (Square pcOther);
	int getSquareSize();

	Node* selection();
	Node* getNode(int x, int y);

	bool isSetValue(Node *node);

	string print();

private:
	Node * *square;
	int square_size;
};

