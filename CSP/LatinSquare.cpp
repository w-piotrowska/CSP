#include "stdafx.h"
#include "LatinSquare.h"


LatinSquare::LatinSquare()
{
}

LatinSquare::LatinSquare(int square_size, int d_size)
{
	square = Square(square_size, d_size);
	domain_size = d_size;
}


LatinSquare::~LatinSquare()
{
}

bool LatinSquare::check(Node* node)
{
	for (int i = 0; i < square.getSquareSize(); i++) {
		if (i != node->getX() && node->getValue() == square.getNode(i, node->getY())->getValue()) {
			return false;
		}
		if (i != node->getY() && node->getValue() == square.getNode(node->getX(), i)->getValue()) {
			return false;
		}
	}
	return true;
}
