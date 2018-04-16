#include "stdafx.h"
#include "ColoringGraph.h"


ColoringGraph::ColoringGraph()
{
}

ColoringGraph::ColoringGraph(int size)
{
	square = Square(size, size);
	domain_size = size;
}


ColoringGraph::~ColoringGraph()
{
}

bool ColoringGraph::check(Node * node)
{
	int edge = 2;
	int corner = 1;
	if (node->getX() > 0) {
		if (square.getNode(node->getX() - 1, node->getY())->getValue() > 0 
			&& abs(square.getNode(node->getX() - 1, node->getY())->getValue() - node->getValue()) < edge) {
			return false;
		}
	}
	if (node->getY() > 0) {
		if (square.getNode(node->getX(), node->getY() - 1)->getValue() > 0
			&& abs(square.getNode(node->getX(), node->getY() - 1)->getValue() - node->getValue()) < edge) {
			return false;
		}
	}
	if (node->getX() > 0 && node->getY() > 0) {
		if (square.getNode(node->getX() - 1, node->getY() - 1)->getValue() > 0
			&& abs(square.getNode(node->getX() - 1, node->getY() - 1)->getValue() - node->getValue()) < corner) {
			return false;
		}
	}
	if (node->getX() > 0 && node->getY() < square.getSquareSize() - 1) {
		if (square.getNode(node->getX() - 1, node->getY() + 1)->getValue() > 0
			&& abs(square.getNode(node->getX() - 1, node->getY() + 1)->getValue() - node->getValue()) < corner) {
			return false;
		}
	}
	if (node->getX() < square.getSquareSize() - 1) {
		if (square.getNode(node->getX() + 1, node->getY())->getValue() - node->getValue() > 0 
			&& abs(square.getNode(node->getX() + 1, node->getY())->getValue() - node->getValue()) < edge) {
			return false;
		}
	}
	if (node->getY() < square.getSquareSize() - 1) {
		if (square.getNode(node->getX(), node->getY() + 1)->getValue() > 0
			&& abs(square.getNode(node->getX(), node->getY() + 1)->getValue() - node->getValue()) < edge) {
			return false;
		}
	}
	if (node->getX() < square.getSquareSize() - 1 && node->getY() > 0) {
		if (square.getNode(node->getX() + 1, node->getY() - 1)->getValue() > 0
			&& abs(square.getNode(node->getX() + 1, node->getY() - 1)->getValue() - node->getValue()) < corner) {
			return false;
		}
	}
	if (node->getX() < square.getSquareSize() - 1 && node->getY() < square.getSquareSize() - 1) {
		if (square.getNode(node->getX() + 1, node->getY() + 1)->getValue() > 0
			&& abs(square.getNode(node->getX() + 1, node->getY() + 1)->getValue() - node->getValue()) < corner) {
			return false;
		}
	}
	return true;
}


