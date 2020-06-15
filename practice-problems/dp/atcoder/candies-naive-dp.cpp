#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int a, int b)
{
	return (0LL + a + b)%mod;
}

void Candies_DP(vector<int> &a, int totalCandies)
{
	int n = a.size();

	vector<vector<int>> dp(n + 1, vector<int>(totalCandies + 1, 0));

	/* dp[len][candy] represents the total number of ways to distribute
	 * 'candy' candies amongst the first 'len' children
	 */

	/* You have to use up all the candies */
	for(int candy = 1; candy <= totalCandies; candy++)
		dp[0][candy] = 0;
	
	// No candy, No children. One way
	dp[0][0] = 1;

	for(int len = 1; len <= n; len++)
	{
		for(int candy = 0; candy <= totalCandies; candy++)
		{

			for(int give = 0; give <= a[len-1]; give++)
			{
				if( give <= candy)
					dp[len][candy] = add(dp[len][candy], dp[len-1][candy-give]);
			}
		}
	}

	cout << dp[n][totalCandies] << endl;
}

int main()
{
	int n, totalCandies;
	cin >> n >> totalCandies;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	Candies_DP(a, totalCandies);
	return 0;
}

					
