#include <bits/stdc++.h>
using namespace std;

/* Verified through Leetcode! */
int rectangle_in_histogram(vector<int> &a)
{
	/* Sentinel : It would pop all the elements from the stack */
	a.push_back(0);

	int res = 0;

	stack<int> stk;
	for(int i = 0; i < a.size(); i++)
	{
		while(not stk.empty() and a[stk.top()] >= a[i])
		{
			int curr = stk.top();
			stk.pop();

			int right_block = i;
			int left_block = -1;

			if(not stk.empty())
				left_block = stk.top();

			int width = right_block - left_block - 1;
			int height = a[curr];

			int side = min(height, width);
			res = max(res, side*side);
		}
		stk.push(i);
	}
	return res;
}

/* Verified through Leetcode */
int maximal_rectangle(vector<vector<int>> &mat)
{
	int row = mat.size();
	int col = mat[0].size();

	int res = 0;

	/* Convert every row to a vertical prefix-sum and compute via histograms */
	for(int i = 0; i < row; i++)
	{
		if(i > 0)
		{
			for(int j = 0; j < col; j++)
				if(mat[i][j] == 1)
					mat[i][j] += mat[i - 1][j];
		}

		res = max(res, rectangle_in_histogram(mat[i]));
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int row, col;

	cin >> row >> col;

	vector<vector<int>> mat(row, vector<int>(col, 0));

	for(auto &row_vec : mat)
		for(auto &ele : row_vec)
			cin >> ele;

	cout << maximal_rectangle(mat) << endl;
	return 0;
}
