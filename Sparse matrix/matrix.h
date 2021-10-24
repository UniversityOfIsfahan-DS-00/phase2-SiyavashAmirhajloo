#include "linkedList.h"

class matrix
{
public:

	void insert(int row, int col, int value);
	int Delete(int row, int col);
	void update(int row, int col, int value);
	void search(int value);
	void print(int type);
private:
	vector<linkedList> rows;
	vector<linkedList> cols;

};
