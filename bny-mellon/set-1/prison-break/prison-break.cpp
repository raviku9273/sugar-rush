#include<bits/stdc++.h>
using namespace std;

int max_gap(int row, vector<int> &break_row)
{
	// `k` bars imply `k + 1` boxes
	row++; 

	vector<int> row_ind(row + 1, 1);

	/* row_ind[1] implies that the i-th row exists */
	for(auto ele : break_row)
		row_ind[ele] = 0;

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

	return max_row_diff;
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
	
	int max_row_gap = max_gap(row, break_row);
	int max_col_gap = max_gap(col, break_col);

	cout << 1LL*max_row_gap*max_col_gap << endl;
	return 0;
}
