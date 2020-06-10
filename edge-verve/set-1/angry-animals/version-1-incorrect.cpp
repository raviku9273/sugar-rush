#include<bits/stdc++.h>
using namespace std;

void AngryAnimals(int n, vector<int> &a, vector<int> &b)
{
	vector<long long> dp(n + 1, 0);
	vector<int> conflict_right(n + 1, n + 1);

	/* conflict_right[i] denotes the smallest index to the right which is conflicting with i */
	/* dp[i] represents the number of groups starting at i */

	for(int i = 0; i < a.size(); i++)
	{
		if( a[i] < b[i])
			conflict_right[a[i]] = min(conflict_right[a[i]], b[i]);

		if( b[i] < a[i] )
			conflict_right[b[i]] = min(conflict_right[b[i]], a[i]);
	}

	for(int i = 1; i <= n; i++)
		dp[i] = conflict_right[i] - i;
	
	cout << accumulate(dp.begin(), dp.end(), 0) << endl;
}

int main()
{
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
