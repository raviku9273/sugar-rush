#include <bits/stdc++.h>
using namespace std;

int getSum(vector<vector<int>> &partial, int x, int y, int p, int q)
{
	int top_left  = x and y ? partial[x-1][y-1]: 0;
	int top_right = x ? partial[x-1][q] : 0;
	int bot_left  = y ? partial[p][y-1] : 0;
	int bot_right = partial[p][q];
	
	int res = bot_right - top_right;
	res -= (bot_left - top_left);
	
	return res;
}

int main()
{
	int row, col;
	cin >> row >> col;

	vector<vector<int>> partial(row, vector<int>(col, 0));

	for(auto &row_vec : partial)
		for(auto &ele : row_vec)
			cin >> ele;

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout << getSum(partial, i, j, i, j) << " ";
		}
		
		cout << endl;
	}

	return 0;
}
