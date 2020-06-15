#include<bits/stdc++.h>
using namespace std;

string solve(string &str, int k)
{
	int n = str.length();

	vector<int> dp(n, 1);

	/* dp[i] is the longest k-interspace string starting at 'i' */

	for(int i = n - 2; i >= 0; i--)
	{
		int diff = abs(str[i] - str[i + 1]);

		if(diff <= k)
			dp[i] = 1 + dp[i + 1];
	}

	int maximal = *max_element(dp.begin(), dp.end());

	for(int i = 0; i < n; i++)
		if(dp[i] == maximal)
			return str.substr(i, maximal);

	assert(false);
}

int main()
{
	string str;
	cin >> str;

	int k;
	cin >> k;

	cout << solve(str, k) << endl;
	return 0;
}

