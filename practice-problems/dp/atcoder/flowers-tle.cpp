#include<bits/stdc++.h>
using namespace std;

void Flowers(vector<long long> &a, vector<int> &h)
{
	int n = a.size();

	vector<long long> dp(n, 0);

	/* dp[height] represents the maximum beauty of a subsequence which ends with height 'height' */
	for(int i = 0; i < n; i++)
	{
		int curr_height = h[i];
		dp[curr_height] = a[i];
		
		long long prefix_max = 0;
		for(int j = 0; j < curr_height; j++)
			prefix_max = max(prefix_max, dp[j]);

		dp[curr_height] += prefix_max;
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> h(n);
	for(auto &ele : h)
	{
		cin >> ele;
		ele--;
	}
	
	vector<long long> a(n);
	for(auto &ele : a)
		cin >> ele;

	Flowers(a, h);
	return 0;
}

