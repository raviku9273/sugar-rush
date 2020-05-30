#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add(int &a, int b)
{
	a = (a + b) % mod;
}

int mult(int a, int b)
{
	return (1LL*a*b)%mod;
}

void solve(vector<string> &collection, string &target)
{
	int max_col = collection.front().length();
	int max_p_len = target.length();

	vector<vector<int>> freq(max_col + 1, vector<int>(26, 0));

	for(auto &str : collection)
		for(int i = 0; i < str.size(); i++)
			freq[i + 1][str[i] - 'a']++;

	vector<vector<int>> dp(max_col + 1, vector<int>(max_p_len + 1, 0));

	/* dp[col][p_len] represents the number of ways to form target[1...p_len]
	 * from the first 'col' columns
	 */

	/* Base Case */
	for(int col = 0; col <= max_col; col++)
		dp[col][0] = 1;
	
	// Switching to one based indexing
	target = '$' + target;

	for(int col = 1; col <= max_col; col++)
	{
		for(int p_len = 1; p_len <= max_p_len; p_len++)
		{
			// Don't take this column
			add(dp[col][p_len], dp[col - 1][p_len]);

			// Take this column
			add(dp[col][p_len], mult(freq[col][target[p_len] - 'a'], dp[col - 1][p_len - 1]));
		}
	}

	cout << dp[max_col][max_p_len] << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<string> a(n);
	for(auto &ele : a)
		cin >> ele;

	string target;
	cin >> target;

	solve(a, target);
	return 0;
}
