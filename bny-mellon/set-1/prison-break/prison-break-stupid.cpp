#include<bits/stdc++.h>
using namespace std;

void prison_break(int row, int col, vector<int> &break_row, vector<int> &break_col)
{
	// This is necessary. See the picture for more details.
	// `k` bars imply `k + 1` boxes
	row++; col++;

	vector<int> row_ind(row + 1, 1);
	vector<int> col_ind(col + 1, 1);

	/* row_ind[1] implies that the i-th row exists */

	for(auto ele : break_row)
		row_ind[ele] = 0;

	for(auto ele : break_col)
		col_ind[ele] = 0;

	int lastSeen = 0;
	int max_row_diff = 0;

	for(int i = 1; i <= row; i++)
	{
		if(row_ind[i])
		{
			max_row_diff = max(max_row_diff, i - lastSeen);
			lastSeen = i;
		}
	}

	lastSeen = 0;
	int max_col_diff = 0;

	for(int j = 1; j <= col; j++)
	{
		if(col_ind[j])
		{
			max_col_diff = max(max_col_diff, j - lastSeen);
			lastSeen = j;
		}
	}

	long long res = 1LL*max_row_diff*max_col_diff;

	cout << res << endl;
}

int main()
{
	int row, col;
	cin >> row >> col;

	int dim;
	cin >> dim;
	
	vector<int> break_row(dim);
	for(auto &ele : break_row)
		cin >> ele;

	cin >> dim;
	vector<int> break_col(dim);
	
	for(auto &ele : break_col)
		cin >> ele;

	prison_break(row, col, break_row, break_col);
	return 0;
}
