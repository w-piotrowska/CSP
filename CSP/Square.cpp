#include "stdafx.h"
#include "Square.h"


Square::Square()
{
}

Square::Square(int size, int domain_size)
{
	square_size = size;
	square = new Node*[square_size];
	for (int i = 0; i < square_size; i++) {
		square[i] = new Node[square_size];
		for (int j = 0; j < square_size; j++) {
			square[i][j] = Node(domain_size, i, j);
		}
	}
}

Square::Square(const Square & pcOther)
{
	square_size = pcOther.square_size;
	square = new Node*[square_size];
	for (int i = 0; i < square_size; i++) {
		square[i] = new Node[square_size];
		for (int j = 0; j < square_size; j++) {
			square[i][j] = pcOther.square[i][j];
		}
	}
}


Square::~Square()
{
	if (square != nullptr) {
		for (int i = 0; i < square_size; i++) {
			if (square[i] != nullptr) {
				//delete square[i];
			}
		}
		delete square;
	}
}

Square Square::operator=(Square pcOther)
{
	square_size = pcOther.square_size;
	square = new Node*[square_size];
	for (int i = 0; i < square_size; i++) {
		square[i] = new Node[square_size];
		for (int j = 0; j < square_size; j++) {
			square[i][j] = pcOther.square[i][j];
		}
	}
	return *this;
}

int Square::getSquareSize()
{
	return square_size;
}

Node * Square::selection()
{
	for (int i = 0; i < square_size; i++) {
		for (int j = 0; j < square_size; j++) {
			if (!isSetValue(getNode(i, j))) {
				return getNode(i, j);
			}
		}
	}
	return nullptr;
}

Node * Square::getNode(int x, int y)
{
	return &square[x][y];
}

bool Square::isSetValue(Node * node)
{
	return(node->getValue() >= 0);
}

string Square::print()
{
	string s = "size = " + to_string(square_size) +"\n";
	for (int i = 0; i < square_size; i++) {
		for (int j = 0; j < square_size; j++) {
			s += getNode(i, j)->printValueOnly() + " ";
			//s += getNode(i, j)->print() + " ";
		}
		s += "\n";
	}
	s += "\n";
	return s;
}
