#include<bits/stdc++.h>
using namespace std;

const long long inf = 1e15 + 7;

long long get_sum(vector<long long> &prefix, int left, int right)
{
	if(left != 0)
		return prefix[right] - prefix[left-1];
	else
		return prefix[right];
}

void Slimes(vector<long long> &a)
{
	int n = a.size();
	vector<long long> prefix = a;
	
	for(int i = 1; i < n; i++)
		prefix[i] += prefix[i-1];

	vector<vector<long long>> dp(n, vector<long long>(n, inf));

	/* dp[i][j] represents the min cost to compress arr[i...j] to 
	 * a single element
	 */

	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = i; j < n; j++)
		{
			if(i == j)
			{
				dp[i][j] = 0;
				continue;
			}

			for(int k = i; k < j; k++)
			{
				auto current_cost = get_sum(prefix, i, j);
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + current_cost);
			}
		}
	}

	cout << dp[0][n-1] << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<long long> a(n);
	for(auto &ele : a)
		cin >> ele;

	Slimes(a);
	return 0;
}

