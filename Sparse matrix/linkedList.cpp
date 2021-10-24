#include "linkedList.h"

linkedList::linkedList()
{
	size = 0;
}

node* linkedList::find(int value)
{
	node* p = head;
	for (int i = 0; i < getSize(); i++) {
		if (p->getElement() == value)
			return p;
		p = p->getRowNext();
	}
	return NULL;
}

bool linkedList::isEmpty()
{
	if (size)
		return true;
	return false;
}

void linkedList::setHead(node* n)
{
	head = n;
}

void linkedList::setTail(node* n)
{
	tail = n;
}

void linkedList::setSize(int n)
{
	size = n;
}