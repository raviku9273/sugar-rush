#include<bits/stdc++.h>
using namespace std;

void knapsack(vector<int> &a, vector<int> &val, int max_weight)
{
	int n = a.size();

	vector<vector<int>> dp(n + 1, vector<int>(max_weight + 1, 0));

	/* Switch to one based indexing */
	a.insert(a.begin(), 0);
	val.insert(val.begin(), 0);

	/* dp[n][weight] represents the maximum profit that you can gain out of
	 * first 'n' items with a knapsack of weight 'weight'
	 */

	for(int i = 1; i <= n; i++)
	{
		for(int weight = 1; weight <= max_weight; weight++)
		{
			dp[i][weight] = dp[i - 1][weight];

			if(a[i] <= weight)
			{
				auto &ele = dp[i][weight];
				ele = max(ele, dp[i - 1][weight - a[i]] + val[i]);
			}
		}
	}
	
	cout << dp[n][max_weight] << endl;
}

void solve()
{
	int n;
	cin >> n;

	vector<int> val(n);
	for(auto &ele : val)
		cin >> ele;

	cin >> n;
	vector<int> a(n);

	for(auto &ele : a)
		cin >> ele, ele *= 2;

	int max_weight;
	cin >> max_weight;

	knapsack(a, val, max_weight);
}

int main()
{
	solve();
	return 0;
}
