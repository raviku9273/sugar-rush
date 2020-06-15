#include<bits/stdc++.h>
using namespace std;

/* Faulty First Draft (Took Hours to debug this)
 * You were doing mod with dp but not prefix sum
 * That was a grave mistake
 */

/* Faulty First Draft (2 Penalties)
 * The mod can become negative, even if the original
 * difference was positive. Why?
 */
const int mod = 1e9 + 7;

inline int add(int a, int b)
{
	long long int x = a;
	long long int y = b;
	
	int res = (x + y)%mod;	

	if(res < 0)
		res += mod;

	return res;
}

void Candies_DP(vector<int> &a, int totalCandies)
{
	int n = a.size();

	vector<vector<int>> dp(n, vector<int>(totalCandies + 1, 0));
	vector<vector<int>> prefix(n, vector<int>(totalCandies + 1, 0));

	/* dp[i][j] represents the total number of ways to distribute j candies
	 * to the children [0...i]
	 */

	/* prefix[i][j] is the sum of dp[i][k] where k ranges from 0 to j */

	/* Base case : One children. The candies should be less than or equal to what he can take */
	
	int i = 0;
	for(int j = 0; j <= totalCandies; j++)
	{
		if( a[0] >= j)
			dp[i][j] = 1;
		
		prefix[i][j] = dp[i][j];

		if( j != 0)
			prefix[i][j] = add(prefix[i][j], prefix[i][j-1]);
	}

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= totalCandies; j++)
		{
			/* dp[i][j] is the sum of all dp[i-1][k]
			 * where k belongs to [j-a[i], j - 0]
			 */
			int left = j - a[i];

			if(left < 0)
				left = 0;

			int right = j;
			
			// Faulty First Draft : Took prefix[i] instead of prefix[i-1]
			dp[i][j] = add(dp[i][j], prefix[i-1][right]);

			if(left != 0)
				dp[i][j] = add(dp[i][j], -1*prefix[i-1][left-1]);
			
			prefix[i][j] = dp[i][j];

			if(j != 0)
				prefix[i][j] = add(prefix[i][j], prefix[i][j-1]);
		}
	}
	
	cout << dp[n-1][totalCandies] << endl;
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

					
