#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

void coin_change(vector<int> &a, int max_val)
{
	int max_n = a.size();
	
	// Long Long DP to allow arithmetic on INT_MAX
	vector<vector<long long>> dp(max_n + 1, vector<long long>(max_val + 1, inf));

	/* dp[n][val] represents the minimum coins to create 'val' amount
	 * from the first 'n' set of coins
	 */

	/* Convert to one based indexing */
	a.insert(a.begin(), 0);
	
	// You don't need any coins
	for(int n = 0; n <= max_n; n++)
		dp[n][0] = 0;

	for(int n = 1; n <= max_n; n++)
	{
		for(int val = 1; val <= max_val; val++)
		{
			// Leave it
			long long res = dp[n - 1][val];

			// Take it once if possible
			if(val >= a[n])
				res = min(res, 1 + dp[n][val - a[n]]);

			dp[n][val] = res;
		}
	}

	if(dp[max_n][max_val] < inf)
		cout << dp[max_n][max_val] << endl;
	else
		cout << -1 << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	int max_val;
	cin >> max_val;

	coin_change(a, max_val);
	return 0;
}
