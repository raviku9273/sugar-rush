#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int a, int b)
{
	return ( a + b ) % mod;
}

void add_self(int &a, int b)
{
	a = (a + b) % mod;
}

const int l = 0, r = 1;

/* dp[i][dest][last] is the number of unique subsequences of first 'i' characters
 * of str, str[1...i] that finish at 'dest' with last character as `last`. 
 * It is assumed that all  sequences start at 'o_start'.
 */

const int maxn = 2520;
int dp[maxn][maxn][2];

void initialize()
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			for(int k = 0; k < 2; k++)
				dp[i][j][k] = 0;

}
int paths_to_a_goal(string str, int lim, int o_start, int o_end)
{
	int str_len = str.length();

	initialize();
	dp[0][o_start][0] = 1;

	/* Switching to one based indexing */
	str = '$' + str;

	for(int i = 1; i <= str_len; i++)
	{
		for(int dest = 0; dest <= lim; dest++)
		{
			/* Don't use the current character */
			dp[i][dest][l] = dp[i - 1][dest][l];
			dp[i][dest][r] = dp[i - 1][dest][r];

			if(dest == 0)
			{
				if(str[i] == 'l')
				{
					add_self(dp[i][dest][l], dp[i - 1][dest + 1][l]);
					add_self(dp[i][dest][l], dp[i - 1][dest + 1][r]);
				}
			}

			if(dest == lim)
			{
				if(str[i] == 'r')
				{
					add_self(dp[i][dest][r], dp[i - 1][dest - 1][l]);
					add_self(dp[i][dest][r], dp[i - 1][dest - 1][r]);
				}
			}

			else if(str[i] == 'l')
			{
				add_self(dp[i][dest][l], dp[i - 1][dest + 1][l]);
				add_self(dp[i][dest][l], dp[i - 1][dest + 1][l]);
			}
			
			else if(str[i] == 'r')
			{
				add_self(dp[i][dest][r], dp[i - 1][dest - 1][l]);
				add_self(dp[i][dest][r], dp[i - 1][dest - 1][r]);
			}

			/*

			if(dest == 0)
			{
				if(str[i] == 'l')
					dp[i][dest][l] = add(dp[i - 1][dest + 1][l], dp[i - 1][dest + 1][r]);
			}

			else if(dest == lim)
			{
				if(str[i] == 'r')
					dp[i][dest][r] = add(dp[i - 1][dest - 1][l], dp[i - 1][dest - 1][r]);
			}
			
			else if(str[i] == 'r')
			{
				dp[i][dest][r] = add(dp[i - 1][dest - 1][l], dp[i - 1][dest - 1][r]);
			}
			
			else if(str[i] == 'l')
			{
				dp[i][dest][l] = add(dp[i - 1][dest + 1][l], dp[i - 1][dest + 1][r]);
			}
			if(dest == o_start and str[i] == 'l')
				add_self(dp[i][dest][l], 1);
			*/
		}
	}
	
	return add(dp[str_len][o_end][l], dp[str_len][o_end][r]);
}

int main()
{
	string str;
	cin >> str;

	int lim, o_start, o_end;
	cin >> lim >> o_start >> o_end;

	cout << paths_to_a_goal(str, lim, o_start, o_end);
	cout << endl;

	return 0;
}
