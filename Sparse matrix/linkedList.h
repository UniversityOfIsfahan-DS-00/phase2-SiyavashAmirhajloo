#include <vector>
#include "node.h"

class linkedList
{
public:
	linkedList();
	node* find(int value);
	bool isEmpty();
	void setHead(node*);
	void setTail(node*);
	void setSize(int);
	node* getHead() { return head; }
	node* getTail() { return tail; }
	int getSize() { return size; }
private:
	node* head;
	node* tail;
	int size;
};