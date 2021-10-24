#include <iostream>

using namespace std;

struct location
{
	int row;
	int col;
};

class node
{
public:
	node(int e, int r, int c);
	void setElement(int e);
	void setLocation(int r, int c);
	void setRowNext(node* n);
	void setColNext(node* n);
	int getElement() { return element; }
	location getLocation() { return loc; }
	node* getRowNext() { return rowNext; }
	node* getColNext() { return colNext; }
private:
	int element;
	location loc;
	node* rowNext;
	node* colNext;
};