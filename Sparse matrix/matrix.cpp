#include "matrix.h"


void matrix::insert(int r, int c, int value)
{
	node* x = new node(value, r, c), * p = rows[r].getHead();
	int i = rows[r].getSize();
	int j = cols[c].getSize();
	if (i == 0) {
		rows[r].setHead(x);
		rows[r].setTail(x);
	}
	else {
		if (c < rows[r].getHead()->getLocation().col) {
			x->setRowNext(rows[r].getHead());
			rows[r].setHead(x);
		}
		else
			if (c > rows[r].getTail()->getLocation().col) {
				rows[r].getTail()->setRowNext(x);
				rows[r].setTail(x);
			}
			else
				while (i--)
				{
					if (p->getRowNext()->getLocation().col > c) {
						x->setRowNext(p->getRowNext());
						p->setRowNext(x);
					}
					else {
						p = p->getRowNext();
					}
				}
	}
	if (j == 0) {
		cols[c].setHead(x);
		cols[c].setTail(x);
	}
	else
		if (r < cols[c].getHead()->getLocation().row) {
			x->setColNext(cols[c].getHead());
			cols[c].setHead(x);
		}
		else
			if (r > cols[r].getTail()->getLocation().row) {
				cols[c].getTail()->setColNext(x);
				cols[c].setTail(x);
			}
			else
				while (j--)
				{
					if (p->getColNext()->getLocation().col > c) {
						x->setColNext(p->getColNext());
						p->setColNext(x);
					}
					else {
						p = p->getColNext();
					}
				}
	rows[r].setSize(i + 1);
	cols[c].setSize(j + 1);
}

int matrix::Delete(int r, int c)
{
	int deleted_data;
	if (rows[r].getHead()->getLocation().row == r && rows[r].getHead()->getLocation().col == c) {
		deleted_data = rows[r].getHead()->getElement();
		rows[r].setHead(NULL);
		rows[r].setTail(NULL);
	}
	else {
		node* p = rows[r].getHead();
		while (p->getRowNext()->getLocation().col != c)
			p = p->getRowNext();
		deleted_data = p->getRowNext()->getElement();
		p->setRowNext(p->getRowNext()->getRowNext());
	}
	if (cols[c].getHead()->getLocation().col == c && cols[c].getHead()->getLocation().row == r) {
		//deleted_data = cols[c].getHead()->getElement();
		cols[c].setHead(NULL);
		cols[c].setTail(NULL);
	}
	else {
		node* p = cols[c].getHead();
		while (p->getColNext()->getLocation().col != r)
			p = p->getColNext();
		//deleted_data = p->getColNext()->getElement();
		p->setColNext(p->getColNext()->getColNext());
	}
	rows[r].setSize(rows[r].getSize() - 1);
	cols[c].setSize(cols[c].getSize() - 1);
	return deleted_data;
}

void matrix::update(int r, int c, int value)
{
	node* p = rows[r].getHead();
	for (int i = 0; i < rows[r].getSize(); i++) {
		if (p->getLocation().col == c) {
			p->setElement(value);
			break;
		}
	}
}

void matrix::search(int value)
{
	for (int i = 0; i < rows.size(); i++) {
		node* p = rows[i].find(value);
		if (p->getElement() == value) {
			cout << "Yes. In row " << p->getLocation().row << " and column " << p->getLocation().col << endl;
			return;
		}
	}
	cout << "No. There is not.\n";
}

void matrix::print(int type)
{
	if (type) {
		for (int i = 0; i < rows.size(); i++) {
			node* p = rows[i].getHead();
			for (int j = 0; j < rows[i].getSize(); j++) {
				if (j == p->getLocation().col) {
					cout << p->getElement() << " ";
					p = p->getRowNext();
				}
				else
					cout << 0 << " ";
			}
			cout << endl;
		}
	}
	else
		for (int i = 0; i < rows.size(); i++) {
			if (!rows[i].isEmpty()) {
				node* p = rows[i].getHead();
				for (int j = 0; j < rows[i].getSize(); j++) {
					cout << p->getLocation().row << " " << p->getLocation().col << " " << p->getElement() << endl;
					p = p->getRowNext();
				}
			}
		}
}

