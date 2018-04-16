#include "stdafx.h"
#include "Node.h"


Node::Node()
{
}

Node::Node(int domain_size)
{
	value = -1;
	domain.resize(domain_size);
	for (int i = 0; i < domain_size; i++) {
		domain[i] = i + 1;
	}
}

Node::Node(int domain_size, int xi, int yi)
{
	value = -1;
	domain.resize(domain_size);
	for (int i = 0; i < domain_size; i++) {
		domain[i] = i + 1;
	}
	x = xi;
	y = yi;
}


Node::~Node()
{
}

int Node::getX()
{
	return x;
}

int Node::getY()
{
	return y;
}

int Node::getValue()
{
	return value;
}

bool Node::setValue()
{
	if (isDomainEmpty()) {
		return false;
	}
	value = domain[0];
	return true;
}

bool Node::deleteFromDomain(int val)
{
	vector<int>::iterator it = domain.begin();
	for (int i = 0; i < domain.size(); i++) {
		if (domain[i] == val) {
			vector<int>::iterator it = domain.begin() + i;
			domain.erase(it);
			return true;
		}
	}
	return false;
}

bool Node::addToDomain(int val)
{
	if (isInDomain(val)) {
		return false;
	}
	domain.push_back(val);
	return true;
}

bool Node::isDomainEmpty()
{
	return domain.empty();
}

void Node::recreate(int domain_size)
{
	value = -1;
	domain.resize(domain_size);
	for (int i = 0; i < domain_size; i++) {
		domain[i] = i + 1;
	}
}

bool Node::isInDomain(int val)
{
	for (int i = 0; i < domain.size(); i++) {
		if (domain[i] == val) {
			return true;
		}
	}
	return false;
}

string Node::print()
{
	string s = "value = " + to_string(value);
	s += "\ndomain = ";
	for (int i = 0; i < domain.size(); i++) {
		s += to_string(domain[i]) + " ";
	}
	s += "\nx = " + to_string(x) + "\ty = " + to_string(y);
	return s;
}

string Node::printValueOnly()
{
	return to_string(value);
}
