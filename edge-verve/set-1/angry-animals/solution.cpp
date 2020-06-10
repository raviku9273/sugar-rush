#include<bits/stdc++.h>
using namespace std;

/* Convert to zero based indexing */
/* Sentinel : The element (n) conflicts with everyone */

void AngryAnimals(int n, vector<int> &a, vector<int> &b)
{
	for(auto &ele : a)
		ele--;

	for(auto &ele : b)
		ele--;

	/* conflict_right[i] denotes the smallest index to the right which is conflicting with i */
	vector<int> conflict_right(n, n);
	for(int i = 0; i < a.size(); i++)
	{
		int min_ind = min(a[i], b[i]);
		int max_ind = max(a[i], b[i]);

		conflict_right[min_ind] = min(conflict_right[min_ind], max_ind);
	}


	/* dp[i] = j implies `j` is the first index to the right of `i` which conflicts with some element
	 * in the segment a[i....j-1]
	 */
	vector<int> dp(n, n);
	dp[n - 1] = n; 
	for(int i = n- 2; i >= 0; i--)
		dp[i] = min(dp[i+1], conflict_right[i]);
	
	/* ways[i] represents the number of groups which start at i (and has no conflicts) */
	vector<long long> ways(n, 0);
	for(int i = 0; i < n; i++)
		ways[i] = dp[i] - i;
	
	/* long long answer = 0; */
	/* for(auto ele : ways) */
	/* 	answer += ele; */

	/* cout << answer << endl; */
	
	/* Bug : Use accumulate very carefully, even if container type is long long */
	cout << accumulate(ways.begin(), ways.end(), 0LL) << endl;
}

int main()
{
	// This is necessary due to large constraints
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int sz;
	cin >> sz;
	vector<int> a(sz), b(sz);

	for(auto &ele : a)
		cin >> ele;

	int fake;
	cin >> fake;

	for(auto &ele : b)
		cin >> ele;

	AngryAnimals(n, a, b);
	return 0;
}
