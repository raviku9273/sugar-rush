#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

void Frog_1(vector<int> &h)
{
	int n = h.size();

	vector<int> dp(n, inf);

	/* dp[i] represents the minimum cost to reach the end when you start at i */
	
	// No out of bound acces due to input constraints
	dp[n-1] = 0;
	dp[n-2] = abs(h[n-1] - h[n-2]);

	for(int i = n-3; i >= 0; i--)
		for(int j = i + 1; j <= i + 2; j++)
			dp[i] = min(dp[i], abs(h[j]-h[i]) + dp[j]);

	cout << dp.front() << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> h(n);
	for(auto &ele : h)
		cin >> ele;

	Frog_1(h);
	return 0;
}
