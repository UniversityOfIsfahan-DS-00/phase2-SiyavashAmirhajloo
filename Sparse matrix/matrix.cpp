#include <fstream>
#include <string.h>
#include <string>
#include <sstream>
#include <cstdio>
#include "matrix.h"

matrix::matrix(int r, int c)
{
	rows = new linkedList[r];
	cols = new linkedList[c];
	setRows_size(r);
	setCols_size(c);
	recieve(r,c);
}

void matrix::setRows_size(int r)
{
	rows_size = r;
}

void matrix::setCols_size(int c)
{
	cols_size = c;
}

void matrix::insert(int r, int c, int value)
{
	node* x = new node(value, r, c);
	int i = rows[r].getSize();
	int j = cols[c].getSize();
	if (i == 0) {
		rows[r].setHead(x);
		rows[r].setTail(x);
	}
	else
		if (c < rows[r].getHead()->getCol()) { 
			x->setRowNext(rows[r].getHead());
			rows[r].setHead(x);
		}
		else
			if (c > rows[r].getTail()->getCol()) {
				rows[r].getTail()->setRowNext(x);
				rows[r].setTail(x);
			}
			else {
				int k = i;
				while (k--) {
					node* p = rows[r].getHead();
					if (p->getRowNext()->getCol() > c) {
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
		if (r < cols[c].getHead()->getRow()) {
			x->setColNext(cols[c].getHead());
			cols[c].setHead(x);
		}
		else
			if (r > cols[c].getTail()->getRow()) {
				cols[c].getTail()->setColNext(x);
				cols[c].setTail(x);
			}
			else {
				int k = j;
				while (k--) {
					node* p = cols[c].getHead();
					if (p->getColNext()->getCol() > c) {
						x->setColNext(p->getColNext());
						p->setColNext(x);
					}
					else {
						p = p->getColNext();
					}
				}
			}
	rows[r].setSize(i + 1);
	cols[c].setSize(j + 1);
}

int matrix::Delete(int r, int c)
{
	int deleted_data;
	if (rows[r].getHead()->getRow() == r && rows[r].getHead()->getCol() == c) {
		deleted_data = rows[r].getHead()->getElement();
		if (rows[r].getSize() == 1) {
			rows[r].setHead(NULL);
			rows[r].setTail(NULL);
		}
		else rows[r].setHead(rows[r].getHead()->getRowNext());
	}
	else {
		node* p = rows[r].getHead();
		while (p->getRowNext()->getCol() != c)
			p = p->getRowNext();
		deleted_data = p->getRowNext()->getElement();
		p->setRowNext(p->getRowNext()->getRowNext());
		if(p->getRowNext()==nullptr)
			rows[r].setTail(p);
	}
	if (cols[c].getHead()->getCol() == c && cols[c].getHead()->getRow() == r) {
		//deleted_data = rows[r].getHead()->getElement();
		if (cols[c].getSize() == 1) {
			cols[c].setHead(NULL);
			cols[c].setTail(NULL);
		}
		else cols[c].setHead(cols[c].getHead()->getColNext());
	}
	else {
		node* p = cols[c].getHead();
		while (p->getColNext()->getCol() != r)
			p = p->getColNext();
		//deleted_data = p->getColNext()->getElement();
		p->setColNext(p->getColNext()->getColNext());
		if (p->getColNext() == nullptr)
			cols[c].setTail(p);
	}
	rows[r].setSize(rows[r].getSize() - 1);
	cols[c].setSize(cols[c].getSize() - 1);
	return deleted_data;
}

void matrix::update(int r, int c, int value)
{
	node* p = rows[r].getHead();
	for (int i = 0; i < rows[r].getSize(); i++) {
		if (p->getCol() == c) {
			p->setElement(value);
			break;
		}
		p = p->getRowNext();
	}
}

void matrix::search(int value)
{
	for (int i = 0; i < rows_size; i++) {
		node* p = rows[i].find(value);
		if (p != nullptr) {
			cout << "Yes. In row " << p->getRow() << " and column " << p->getCol() << endl;
			return;
		}
	}
	cout << "No. There is not.\n";
}

void matrix::print(int type)
{
	if (type == 0) {
		for (int i = 0; i < rows_size; i++) {
			if (rows[i].getSize()) {
				node* p = rows[i].getHead();
				for (int j = 0; j < cols_size; j++) {
					if (p != nullptr)
						if (j == p->getCol()) {
							cout << p->getElement() << " ";
							p = p->getRowNext();
						}
						else
							cout << 0 << " ";
					else
						cout << 0 << " ";
				}
			}
			else
				for (int j = 0; j < cols_size; j++)
					cout << 0 << " ";
			cout << endl;
		}
	}
	else
		for (int i = 0; i < rows_size; i++) {
			if (rows[i].getSize()) {
				node* p = rows[i].getHead();
				for (int j = 0; j < rows[i].getSize(); j++) {
					cout << p->getRow() << " " << p->getCol()  << " " << p->getElement() << endl;
					p = p->getRowNext();
				}
			}
		}
}

void matrix::recieve(int r, int c)
{
	ifstream m;
	if (r == 10 && c == 5)
		m.open("M(10,5).csv");
	if (r == 300 && c == 200)
		m.open("M(300,200).csv");
	if (r == 7000 && c == 9000)
		m.open("M(7000,9000).csv");
	for (int i = 0; i < r; i++) {
		string line;
		getline(m, line, '\n');
		stringstream linestream(line);
		for (int j = 0; j < c; j++) {
			string temp;
			getline(linestream, temp, ',');
			int value = stoi(temp);
			if (value != 0)
				insert(i, j, value);
		}
	}
	m.close();
}

void matrix::save()
{
	ifstream m;
	if (rows_size == 10 && cols_size == 5)
		m.open("M(10,5).csv");
	if (rows_size == 300 && cols_size == 200)
		m.open("M(300,200).csv");
	if (rows_size == 7000 && cols_size == 9000)
		m.open("M(7000,9000).csv");
	ofstream temp("temp.csv", ios::out);
	for (int i = 0; i < rows_size; i++) {
		if (rows[i].getSize()) {
			node* p = rows[i].getHead();
			for (int j = 0; j < cols_size; j++) {
				if (p != nullptr)
					if (j == p->getCol()) {
						temp << to_string(p->getElement());
						p = p->getRowNext();
					}
					else
						temp << "0";
				else
					temp << "0";
				if (j < cols_size - 1)
					temp << ",";
			}
		}
		else
			for (int j = 0; j < cols_size; j++) {
				temp << "0";
				if (j < cols_size - 1)
					temp << ",";
			}
		temp << '\n';
	}
	temp.close();
	m.close();
	if (rows_size == 10 && cols_size == 5) {
		remove("M(10,5).csv");
		rename("temp.csv", "M(10,5).csv");
	}
	if (rows_size == 300 && cols_size == 200) {
		remove("M(300,200).csv");
		rename("temp.csv", "M(300,200).csv");
	}
	if (rows_size == 7000 && cols_size == 9000) {
		remove("M(7000,9000).csv");
		rename("temp.csv", "M(7000,9000).csv");
	}
}