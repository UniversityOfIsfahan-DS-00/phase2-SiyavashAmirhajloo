#include <iostream>

using namespace std;

class node
{
public:
	node(int e, int r, int c);
	void setElement(int e);
	void setRow(int r);
	void setCol(int c);
	void setRowNext(node* n);
	void setColNext(node* n);
	int getElement() { return element; }
	int getRow() { return row; }
	int getCol() { return col; }
	node* getRowNext() { return rowNext; }
	node* getColNext() { return colNext; }
private:
	int element;
	int row;
	int col;
	node* rowNext;
	node* colNext;
};