#include<bits/stdc++.h>
using namespace std;

void Knapsack_1(vector<int> &weight, vector<int> &val, int maxCap)
{
	int n = weight.size();
	
	// It's very important to make DP as long long
	vector<vector<long long>> dp(n + 1, vector<long long>(maxCap + 1, 0));

	/* dp[n][cap] represents the maximum value that you can get from the first 'n' items
	 * with a knapsack of capactiy 'cap'
	 */

	// No elements to choose from 
	for(int cap = 0; cap <= maxCap; cap++)
		dp[0][cap] = 0;
	
	// The knapsack has zero capacity
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int cap = 0; cap <= maxCap; cap++)
		{
			long long take_it = 0, leave_it = 0;

			if(weight[i-1] <= cap)
				take_it = val[i-1] + dp[i-1][cap - weight[i-1]];

			leave_it = dp[i-1][cap];

			dp[i][cap] = max(take_it, leave_it);
		}
	}

	cout << dp.back().back() << endl;
}

int main()
{
	int n, maxCap;
	cin >> n >> maxCap;

	vector<int> weight(n), val(n);

	for(int i = 0; i < n; i++)
		cin >> weight[i] >> val[i];

	Knapsack_1(weight, val, maxCap);
	return 0;
}



