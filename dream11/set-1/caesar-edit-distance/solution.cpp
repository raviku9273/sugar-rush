#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

int edit_distance(string source, string target)
{
	int source_len = source.length();
	int target_len = target.length();

	vector<vector<int>> dp(source_len + 1, vector<int>(target_len + 1, inf));

	/* Convert to one based indexing */
	source = '$' + source;
	target = '$' + target;

	/* Second string is empty : Only deletions */
	for(int i = 0; i <= source_len; i++)
		dp[i][0] = i;

	/* First string is empty : Only insertions */
	for(int j = 0; j <= target_len; j++)
		dp[0][j] = j;


	for(int i = 1; i <= source_len; i++)
	{
		for(int j = 1; j <= target_len; j++)
		{
			if(source[i] == target[j])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				int delete_it = dp[i - 1][j];
				int insert_it = dp[i][j - 1];

				dp[i][j] = 1 + min(delete_it, insert_it);
			}
		}
	}

	return dp[source_len][target_len];
}

int caesar_edit_distance(string source, string target)
{
	string source_backup = source;

	int res = inf;
	for(int shift = 0; shift < 26; shift++)
	{
		
		for(int i = 0; i < source.length(); i++)
		{
			int val = source_backup[i] - 'a';
			val = (val + shift) % 26;

			source[i] = 'a' + val;
		}

		res = min(res, edit_distance(source, target));
	}
	
	return res;
}

int main()
{
	string source, target;
	cin >> source >> target;

	cout << caesar_edit_distance(source, target) << endl;
	return 0;
}
