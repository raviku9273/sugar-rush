#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

/*
int LIS_Brute(vector<int> &a)
{
	int n = a.size();

	vector<int> dp(n + 1, inf);

	dp[0] = -inf;

	for(auto ele : a)
		for(int len = 1; len <= n; len++)
			if(dp[len - 1] < ele and ele < dp[len])
				dp[len] = ele;

	int res = 0;
	for(int len = 1; len <= n; len++)
		if(dp[len] < inf)
			res = max(res, len);

	return res;
}
*/

int LIS_Optimized(vector<int> &a)
{
	int n = a.size();

	vector<int> dp(n + 1, inf);
	dp[0] = -inf;

	/* dp[len] is the smallest element at which an increasing subsequence 
	 * of length len ends. It's inf if there is no such sequence.
	 */

	for(auto ele : a)
	{
		int len = upper_bound(dp.begin(), dp.end(), ele) - dp.begin();

		if(dp[len - 1] < ele and ele < dp[len])
			dp[len] = ele;
	}

	int res = 0;
	for(int len = 1; len <= n; len++)
		if(dp[len] < inf)
			res = max(res, len);

	return res;
}

int solve(vector<int> &a)
{
	return LIS_Optimized(a);
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	cout << solve(a) << endl;
	return 0;
}


