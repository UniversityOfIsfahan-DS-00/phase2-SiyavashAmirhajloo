#include "node.h"

node::node(int e, int r, int c)
{
	setElement(e);
	setRow(r);
	setCol(c);
	setRowNext(NULL);
	setColNext(NULL);
}

void node::setElement(int e)
{
	element = e;
}

void node::setRow(int r)
{
	row = r;
}

void node::setCol(int c)
{
	col = c;
}

void node::setRowNext(node* n)
{
	rowNext = n;
}

void node::setColNext(node* n)
{
	colNext = n;
}