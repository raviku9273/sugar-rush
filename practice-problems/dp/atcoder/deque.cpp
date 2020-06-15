#include<bits/stdc++.h>
using namespace std;

/* Faulty First Draft : Forgot the long long Datatype for DP */

long long get_sum(vector<long long> &prefix, int left, int right)
{
	if(left != 0)
		return prefix[right] - prefix[left-1];
	else
		return prefix[right];
}

void Deque(vector<long long> &a)
{
	int n = a.size();

	vector<long long> prefix = a;

	for(int i = 1; i < n; i++)
		prefix[i] += prefix[i-1];
	
	vector<vector<long long>> dp(n, vector<long long>(n, 0));

	/* dp[i][j] is the maximum value that the starting player of the game can get 
	 * if the game only has the elements arr[i...j] 
	 */

	for(int i = n-1;  i >= 0; i--)
	{
		for(int j = i; j < n; j++)
		{
			int len = j - i + 1;

			if( len == 1)
			{
				dp[i][j] = a[i];
				continue;
			}
			
			// Faulty First Draft. Wrote get_sum(i, j) in both places
			long long pick_first = a[i] + get_sum(prefix, i+1, j) - dp[i+1][j];
			long long pick_last = a[j] + get_sum(prefix, i, j-1) - dp[i][j-1];

			dp[i][j] = max(pick_first, pick_last);
		}
	}
	
	// After simplification, (x-y) =  ( 2*x - total_sum) 
	cout << 2*dp[0][n-1] - get_sum(prefix, 0, n-1) << endl;
}

int main()
{
	int n;
	cin >> n;
	
	vector<long long> a(n);
	for(auto &ele : a)
		cin >> ele;

	Deque(a);
	return 0;
}
