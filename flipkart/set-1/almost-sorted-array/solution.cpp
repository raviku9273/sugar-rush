#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

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

int almost_sorted(vector<int> &a)
{
	int n = a.size();

	int res = max(0, n - LIS_Optimized(a) - 1);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	cout << almost_sorted(a) << endl;
	return 0;
}


