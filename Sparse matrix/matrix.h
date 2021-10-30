#include "linkedList.h"

class matrix
{
public:
	matrix(int numOfRows, int numOfCols);
	void insert(int row, int col, int value);
	int Delete(int row, int col);
	void update(int row, int col, int value);
	void search(int value);
	void print(int type);
	void save();
	void recieve(int r, int c);
	void setRows_size(int);
	void setCols_size(int);
	int getRows_size() { return rows_size; }
	int getCols_size() { return cols_size; }
private:
	linkedList* rows;
	linkedList* cols;
	int rows_size;
	int cols_size;
};