#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int x, int y)
{
	return (0LL + x + y)%mod;
}

void Matching(vector<vector<bool>> &compatible)
{
	int n = compatible.size();
	
	// Biggest mask happens when all the women are available
	int biggest_mask = ( 1 << n) - 1;

	vector<vector<int>> dp(n, vector<int>(biggest_mask + 1, 0));
	
	for(int i = 0; i < n; i++)
	{
		for(int mask = 0; mask <= biggest_mask; mask++)
		{
			for(int j = 0; j < n; j++)
			{
				// Women should be available and compatible
				if( compatible[i][j] and (mask & (1 << j)) )
				{
					// Turn off the j-th bit (which was set initially)
					int new_mask = mask xor ( 1 << j);
				
					if( i == 0)
						dp[i][mask] = add(dp[i][mask], new_mask == 0);
					else
						dp[i][mask] = add(dp[i][mask], dp[i-1][new_mask]);
				}
			}
		}
	}

	cout << dp[n-1][biggest_mask] << endl;
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

