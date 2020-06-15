#include<bits/stdc++.h>
using namespace std;

int maxVal = 1e5;
const int inf = 2*1e9;

int Knapsack_2(vector<int> &weight, vector<int> &profit, int maxCap)
{
	int n = weight.size();
	
	// It's very important to make DP as long long
	vector<vector<long long>> dp(n + 1, vector<long long>(maxVal + 1, 0));

	/* dp[n][val] represents the minimum capacity of knapsack needed to gain exactly 'val' profit
	 * from the first 'n' elements
	 */

	// No element. There is no way to make any profit
	for(int val = 1; val <= maxVal; val++)
		dp[0][val] = inf;
	
	// An empty knapsack is needed to create zero profit
	for(int i = 1; i <= n; i++)
		dp[i][0] = 0;
	
	// No element and No Profit ==> Empty knapsack would work
	dp[0][0] = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int val = 0; val <= maxVal; val++)
		{
			long long take_it = inf, leave_it = inf;

			leave_it = dp[i-1][val];

			if(val >= profit[i-1])
				take_it = weight[i-1] + dp[i-1][val - profit[i-1]];
			
			dp[i][val] = min(take_it, leave_it);
		}
	}

	for(int ans = maxVal; ans >= 0; ans--)
		if(dp[n][ans] <= maxCap)
			return ans;

}
int main()
{
	int n, maxCap;
	cin >> n >> maxCap;

	vector<int> weight(n), val(n);

	for(int i = 0; i < n; i++)
		cin >> weight[i] >> val[i];

	cout <<	Knapsack_2(weight, val, maxCap);
	return 0;
}



