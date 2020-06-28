#include <bits/stdc++.h>
using namespace std;

int funPal(string str)
{
	int n = str.length();

	vector<vector<int>> dp(n, vector<int>(n, 0));
	/* dp[i][j] is the length of the LPSubsequence of str[i...j] */

	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = i; j < n; j++)
		{
			int len = j - i + 1;

			if(len == 1)
			{
				dp[i][j] = 1;
				continue;
			}

			if(len == 2)
			{
				dp[i][j] = 1 + (str[i] == str[j]);
				continue;
			}

			if(str[i] == str[j])
			{
				dp[i][j] = 2 + dp[i + 1][j - 1];
				continue;
			}

			dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
		}
	}

	int res = 0;
	
	/* First part : str[0...mid], Second Part : str[mid + 1....n - 1] */
	for(int mid = 0; mid < (n - 1); mid++)
		res = max(res, dp[0][mid]*dp[mid + 1][n - 1]);

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	cout << funPal(str) << endl;
	return 0;
}

