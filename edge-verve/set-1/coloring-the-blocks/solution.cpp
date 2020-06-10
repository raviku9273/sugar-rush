#include<bits/stdc++.h>
using namespace std;

const int inf = 1e7;

int colour_the_blocks(vector<vector<int>> &cost)
{
	int n = cost.size();

	vector<vector<int>> dp(n, vector<int>(3, inf));

	/* dp[i][color] represents the minimum cost to color 
	 * a[0...i] when you color the i-th vertex(zero index) with color 'color'
	 */
	
	for(int color = 0; color < 3; color++)
		dp[0][color] = cost[0][color];

	for(int i = 1; i < n; i++)
	{
		for(int last_color = 0; last_color < 3; last_color++)
		{
			for(int curr_color = 0; curr_color < 3; curr_color++)
			{
				if(curr_color == last_color)
					continue;

				dp[i][curr_color]= min(dp[i][curr_color], dp[i-1][last_color] + cost[i][curr_color]);
			}
		}
	}

	int res = inf;
	for(int color = 0; color < 3; color++)
		res = min(res, dp[n-1][color]);

	return res;
}

int main()
{
	int n;
	cin >> n;
	
	vector<vector<int>> cost(n, vector<int>(3, 0));

	for(auto &row_vec : cost)
		for(auto &ele : row_vec)
			cin >> ele;

	cout << colour_the_blocks(cost) << endl;
	return 0;
}
