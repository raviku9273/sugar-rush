#include <bits/stdc++.h>
using namespace std;

/* State 1 : You have left contiguous 'L'
 * State 2 : You have left contiguous 'R'
 * State 3 : You have left contiguous 'L' and 'R'
 * State 4 : Otherwise
 */

vector<vector<vector<int>>> dp;
string str;
int finish, lim;

const int mod = 1e9 + 7;

inline int add(int a, int b)
{
	return (a + b) % mod;
}

int recurse(int ind, int start, int state)
{
	// You've left both 'l' and 'r' previously
	if(state == 3)
	{
		return (start == finish);
	}

	if(ind >= (int)str.length())
	{
		return (start == finish);
	}

	if(start < 0 or start > lim)
		return 0;

	if(dp[ind][start][state] != -1)
		return dp[ind][start][state];

	// You've left 'l' in the last step
	if(state == 1)
	{
		int res;
		if(str[ind] == 'r')
		{
			// Take it and reset everything
			int take_it = recurse(ind + 1, start + 1, 4);

			// Leave it, (and switch to state 3)
			int leave_it = recurse(ind + 1, start, 3);

			res = add(take_it, leave_it);
		}
		else if(str[ind] == 'l')
		{
			// You have to leave it.
			int leave_it = recurse(ind + 1, start, 1);

			res = leave_it;
		}

		dp[ind][start][state] = res;
		return res;
	}
	
	// You've left 'r' in the last step
	if(state == 2)
	{
		int res;
		if(str[ind] == 'l')
		{
			// Take it and reset everything
			int take_it = recurse(ind + 1, start - 1, 4);

			// Leave it, and switch to state 3
			int leave_it = recurse(ind + 1, start, 3);

			res = add(take_it, leave_it);
		}
		else if(str[ind] == 'r')
		{
			// You have to leave it
			int leave_it = recurse(ind + 1, start, 2);

			res = leave_it;
		}

		dp[ind][start][state] = res;
		return res;
	}

	/* Assume that the state is 4 now */
	if(str[ind] == 'l')
	{
		int res;

		// Take it, and remain in state 4
		int take_it = recurse(ind + 1, start - 1, 4);

		// Leave it and switch to state 1
		int leave_it = recurse(ind + 1, start, 1);

		res = add(take_it, leave_it);

		dp[ind][start][state] = res;
		return res;
	}

	if(str[ind] == 'r')
	{
		int res;

		// Take it, and remain in state 4
		int take_it = recurse(ind + 1, start + 1, 4);

		// Leave it and switch to state 2
		int leave_it = recurse(ind + 1, start, 2);

		res = add(take_it, leave_it);

		dp[ind][start][state] = res;
		return res;
	}

	assert(false);
}

int main()
{
	cin >> str;

	int start;

	cin >> lim;
	cin >> start >> finish;


	dp.resize(str.length() + 3);

	for(auto &vec_2d: dp)
		vec_2d.resize(lim + 3, vector<int>(6, -1));

	cout << recurse(0, start, 4) << endl;
	return 0;
}
