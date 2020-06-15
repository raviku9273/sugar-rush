#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int x, int y)
{
	return (0LL + x + y)%mod;
}

class Solution
{
public:
	int n;
	vector<map<int, int>> memo;
	vector<vector<bool>> compatible;
public:
	int recurse(int i, int mask);
};

int Solution :: recurse(int i, int mask)
{
	if(i < 0)
		return (mask == 0);
	
	if(memo[i].find(mask) != memo[i].end())
		return memo[i][mask];

	int res = 0;
	for(int j = 0; j < n; j++)
		if(compatible[i][j] and (mask & (1 << j)) )
			res = add(res, recurse(i-1, mask xor (1 << j)));

	memo[i][mask] = res;
	return res;
}

void Matching(vector<vector<bool>> &compatible)
{
	int n = compatible.size();

	Solution sol;
	sol.n = n;
	sol.compatible = compatible;
	sol.memo.resize(n);
	

	// Biggest mask happens when all the women are available
	int biggest_mask = ( 1 << n) - 1;

	cout << sol.recurse(n-1, biggest_mask) << endl;
	return;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<bool>> compatible(n, vector<bool>(n, false));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int val;
			cin >> val;

			compatible[i][j] = ( val == 1);
		}
	}

	Matching(compatible);
	return 0;
}

