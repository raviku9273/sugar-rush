#include<bits/stdc++.h>
using namespace std;

/* Things in favour : Array does not contain negative elements */

/* Maximum length of a subarray which has sum <= k */
int Arbitrary_Shopping(vector<int> &a, int k)
{
	int n = a.size();
	vector<int> prefix = a;
	
	for(int i = 1; i < n; i++)
		prefix[i] += prefix[i-1];
	
	/* dp[i] represents the longest subarrays starting at `i` with sum <= k */
	vector<int> dp(n, 0);
	int last_val = 0;
	for(int i = 0; i < n; i++)
	{
		int ind = upper_bound(prefix.begin(), prefix.end(), last_val + k) - prefix.begin();
		last_val = prefix[i];

		dp[i] = ind - i;
	}

	return *max_element(dp.begin(), dp.end());
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	int k;
	cin >> k;

	cout << Arbitrary_Shopping(a, k) << endl;
	return 0;
}
