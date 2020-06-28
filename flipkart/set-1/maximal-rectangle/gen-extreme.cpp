#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int row_low = 1000;
const int row_high = 1000;
const int col_low = 1000;
const int col_high = 1000;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_mat()
{
	int row = rnd.next(row_low, row_high);
	int col = rnd.next(col_low, col_high);

	vector<vector<int>> mat(row, vector<int>(col, 1));

	int thresh = row*col/4;
	int set_zero = rnd.next(0, thresh);

	while(set_zero--)
	{
		int i = rnd.next(0, row - 1);
		int j = rnd.next(0, col - 1);

		mat[i][j] = 0;
	}

	cout << row << " " << col << endl;
	for(auto &row_vec : mat)
	{
		for(auto &ele : row_vec)
			cout << ele << " ";

		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_mat();
	return 0;
}

