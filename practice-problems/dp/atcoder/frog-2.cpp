#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

/* Penalty : 1) Out of Bound Access on the first submission
             2) Didn't start from n-2 on the second submission
*/

void Frog_2(vector<int> &h, int k)
{
	int n = h.size();

	vector<int> dp(n, inf);

	/* dp[i] represents the minimum cost to reach the end when you start at i */
	
	// No out of bound acces due to input constraints
	dp[n-1] = 0;

	for(int i = n-2; i >= 0; i--)
	{
		for(int j = i + 1; j <= i + k; j++)
		{
			if(j >= n)
				continue;

			dp[i] = min(dp[i], abs(h[j]-h[i]) + dp[j]);
		}
	}

	cout << dp.front() << endl;
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> h(n);
	for(auto &ele : h)
		cin >> ele;

	Frog_2(h, k);
	return 0;
}
