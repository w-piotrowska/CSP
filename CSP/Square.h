#pragma once
#include "Node.h"
class Square
{
public:
	Square();
	Square(int size);
	~Square();

	Node* selection();
	Node* getNode(int x, int y);

private:
	Node * *square;
	int square_size;
};

