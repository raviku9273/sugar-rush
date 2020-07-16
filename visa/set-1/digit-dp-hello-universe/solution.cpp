#include <bits/stdc++.h>
using namespace std;

/* The catch is to not count prefix zeroes */

int req_digit, req_cnt;
const int max_len = 19;

vector<int> a;
vector<vector<vector<vector<long long>>>> dp;

long long rec(int pos, int cnt, bool flag, bool started)
{
	if(pos == a.size())
		return (cnt == req_cnt);

	if(cnt > req_cnt)
		return 0;

	auto &res = dp[pos][cnt][flag][started];

	if(res != -1)
		return res;

	/* Initialisation is important */
	res = 0;

	/* Now you can place any digit that you want */
	if(flag == true)
	{
		for(int d = 0; d < 10; d++)
		{
			if(req_digit == 0 and d == 0)
				res += rec(pos + 1, cnt + started, true, started);
			else
				res += rec(pos + 1, cnt + (d == req_digit), true, true);
		}
	}

	/* You cannot place a bigger digit */
	if(flag == false)
	{
		/* Place identical digits */
		res += rec(pos + 1, cnt + (a[pos] == req_digit), false, 1);

		/* Place strictly smaller digit */
		for(int d = 0; d < a[pos]; d++)
		{
			if(req_digit == 0 and d == 0)
				res += rec(pos + 1, cnt + started, true, started);
			else
				res += rec(pos + 1, cnt + (d == req_digit), true, true);
		}
	}

	return res;
}

long long solve(long long num)
{
	dp.clear();
	
	vector<vector<long long>> vec_2d(2, vector<long long>(2, -1));

	dp.resize(max_len + 2);

	for(auto &vec_3d : dp)
		vec_3d.resize(max_len + 2, vec_2d);

	a.clear();
	while(num)
	{
		a.push_back(num%10);
		num /= 10;
	}
	reverse(a.begin(), a.end());

	return rec(0, 0, false, false);
}

int main()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		long long low, high;
		cin >> low >> high >> req_digit >> req_cnt;

		auto res = solve(high) - solve(low - 1);
		cout << res << endl;
	}
	
	return 0;
}

/* Note to Self : 
 * 1. Don't include leading zeroes as it would give incorrect answer when `d == 0`
 * 2. Always clear DP/array before resizing, even if there is a single test-case. Why? 
 *    This is because in one test-case, you call it 2 times.
 * 3. Be careful with counting prefix zeroes
 */

/* a.resize(max_len, 0) --> Fails for 12 19 0 0 */
