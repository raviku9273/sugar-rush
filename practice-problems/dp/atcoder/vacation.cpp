#include<bits/stdc++.h>
using namespace std;

void Vacation(vector<vector<int>> &profit)
{
	int n = profit.size();

	vector<vector<int>> dp(n, vector<int>(3, 0));

	/* dp[i][act] represents the total profit that you can get till i-th day 
	 * when you choose the act activity on the i-th day
	 */
	
	for(int act = 0; act <3; act++)
		dp[0][act] = profit[0][act];

	for(int i = 1; i < n; i++)
	{
		for(int prev_act = 0; prev_act < 3; prev_act++)
		{
			for(int curr_act = 0; curr_act < 3; curr_act++)
			{
				if(prev_act == curr_act)
					continue;

				dp[i][curr_act] = max(dp[i][curr_act], dp[i-1][prev_act] + profit[i][curr_act]);
			}
		}
	}

	int res = 0;
	for(int last_act = 0; last_act < 3; last_act++)
		res = max(res, dp.back()[last_act]);

	cout << res << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> profit(n, vector<int>(3, 0));

	for(auto &row_vec : profit)
		for(auto &ele : row_vec)
			cin >> ele;

	Vacation(profit);
	return 0;
}
