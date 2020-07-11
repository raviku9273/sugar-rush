#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int a, int b)
{
	return (0LL + a + b) % mod;
}

int unique_subsequences(string src, string tar)
{
	int src_len = src.length();
	int tar_len = tar.length();

	/* Switch to one based indexing */
	src = '$' + src;
	tar = '$' + tar;

	vector<vector<int>> dp(src_len + 1, vector<int>(tar_len + 1, 0));

	/* dp[i][j] is the number of subsequences of the first i characters of 'src'
	 * which matches the first 'j' characters of 'tar'
	 */

	dp[0][0] = 1;

	/* 'tar' is empty */
	for(int i = 0; i <= src_len; i++)
		dp[i][0] = 1;

	for(int i = 1; i <= src_len; i++)
	{
		for(int j = 1; j <= tar_len; j++)
		{
			int take_it = dp[i - 1][j - 1];
			int leave_it = dp[i - 1][j];

			auto &res = dp[i][j];

			if(src[i] == tar[j])
				res = add(take_it, leave_it);
			else
				res = leave_it;
		}
	}

	return dp[src_len][tar_len];
}

int main()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int sz;
		cin >> sz;

		string src;
		cin >> src;

		string tar = "";
		for(char letter = 'a'; letter <= 'z'; letter++)
			tar += letter;

		cout << unique_subsequences(src, tar);
		cout << endl;
	}

	return 0;
}

/* Always Hanlde 'i == 0' and `j == 0` manually */
