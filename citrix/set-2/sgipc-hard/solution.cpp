#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void add(int &a, int &b)
{
	a = (a + b)%mod;
}

int sgipc(int max_n, int max_k)
{
	// Provide one object to each box
	if(max_n < max_k)
		return 0;
	else
		max_n -= max_k;
	
	vector<vector<int>> dp(max_n + 1, vector<int>(max_k + 1, 0));

	/* dp[n][k] represents the number of ways to distribute `n` unlabelled objects
	 * to `k` labelled boxes in an incremental way
	 */
	
	/* Base Case : 
	 * If there are no boxes, you performed an illegal move
	 * If there are no objects left, you are good to go.
	 * Remember, you already placed one object in each box
	 */
	
	for(int rem_box = 0; rem_box <= max_k; rem_box++)
		dp[0][rem_box] = 1;

	for(int rem_ob = 1; rem_ob <= max_n; rem_ob++)
	{
		for(int rem_box = 1; rem_box <= max_k; rem_box++)
		{
			// If you want to place 1 in the current box, you need to place 
			// it in all other boxes as well.
			if( rem_ob >= rem_box)
			{
				add(dp[rem_ob][rem_box], dp[rem_ob - rem_box][rem_box]);
			}

			// Stop inserting elements in the current box
			add(dp[rem_ob][rem_box], dp[rem_ob][rem_box - 1]);
		}
	}

	return dp[max_n][max_k];
}

int main()
{
	int max_n, max_k;
	cin >> max_n >> max_k;

	cout << sgipc(max_n, max_k) << endl;
}
