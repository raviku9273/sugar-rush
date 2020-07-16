#include <bits/stdc++.h>
using namespace std;

int req_digit, req_cnt;
const int max_len = 19;

vector<int> a;
vector<vector<vector<long long>>> dp;

long long rec(int pos, int cnt, bool flag)
{
	if(pos == max_len)
		return (cnt == req_cnt);

	if(cnt > req_cnt)
		return 0;

	auto &res = dp[pos][cnt][flag];

	if(res != -1)
		return res;

	/* Initialisation is important */
	res = 0;

	/* Now you can place any digit that you want */
	if(flag == true)
	{
		for(int d = 0; d < 10; d++)
			res += rec(pos + 1, cnt + (d == req_digit), true);
	}

	/* You cannot place a bigger digit */
	if(flag == false)
	{
		/* Place identical digits */
		res += rec(pos + 1, cnt + (a[pos] == req_digit), false);

		/* Place strictly smaller digit */
		for(int d = 0; d < a[pos]; d++)
			res += rec(pos + 1, cnt + (d == req_digit), true);
	}

	return res;
}

long long solve(long long num)
{
	dp.clear();
	dp.resize(max_len + 1);
	for(auto &vec_2d : dp)
		vec_2d.resize(max_len + 1, vector<long long>(2, -1));

	a.clear();
	while(num)
	{
		a.push_back(num%10);
		num /= 10;
	}

	a.resize(max_len , 0);

	reverse(a.begin(), a.end());
	for(auto ele : a)
		cout << ele;
	cout << endl;


	return rec(0, 0, false);
}


int main()
{
	long long low, high;
	cin >> low >> high >> req_digit >> req_cnt;
	auto res = solve(high) - solve(low - 1);
	cout << solve(high) << " Yes " << endl;
	cout << res << endl;
	cerr << res << endl;
	
	return 0;
}
