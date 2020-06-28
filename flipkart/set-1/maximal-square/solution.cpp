#include <bits/stdc++.h>
using namespace std;

/* Verified through Leetcode */
int maximal_square(vector<vector<int>> &mat)
{
	int row = mat.size();
	int col = mat[0].size();

	vector<vector<int>> dp(row, vector<int>(col, 0));
	
	/* dp[i][j] is the side of maximal square ending at (i, j) */


	for(int i = 0; i < row; i++)
		dp[i][0] = (mat[i][0] == 1);

	for(int j = 0; j < col; j++)
		dp[0][j] = (mat[0][j] == 1);

	for(int i = 1; i < row; i++)
	{
		for(int j = 1; j < col; j++)
		{
			if(mat[i][j] == 0)
				continue;

			dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
		}
	}

	int res = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			res = max(res, dp[i][j]);

	return res*res;
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

	cout << maximal_square(mat) << endl;
	return 0;
}

/* Note to self : Take max after populating DP, as you'll miss out first row/col */
