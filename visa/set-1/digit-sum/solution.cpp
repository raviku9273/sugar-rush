#include <bits/stdc++.h>
using namespace std;

const int max_sum = 165;

vector<vector<vector<long long>>> dp;
vector<int> a;
int req_sum;

/* dp[pos][sum][flag] represents the total numbers less than or equal to 'high'
 * which has a desired sum 'req_sum' such that you have already placed digits till
 * 'pos - 1' and those digits have sum 'sum' and 
 * 'flag' denotes whether you've placed a strictly smaller digit in a significant place
 */

long long rec(int pos, int sum, bool flag)
{
	if(pos == a.size())
		return (sum == req_sum);
	
	if(sum > req_sum)
		return 0;

	auto &res = dp[pos][sum][flag];

	if(res != -1)
		return res;

	/* Don't forget to initialize */
	res = 0;

	/* Now you can place any digit that you want */
	if(flag == true)
	{
		for(int d = 0; d < 10; d++)
		{
			res += rec(pos + 1, sum + d, true);
		}
	}

	/* You have to place smaller/identical digits */
	if(flag == false)
	{
		// Place identical digits
		res += rec(pos + 1, sum + a[pos], false);

		// Place strictly smaller digit
		for(int d = 0; d < a[pos]; d++)
			res += rec(pos + 1, sum + d, true);
	}

	return res;
}

long long solve(long long num)
{
	/* Don't forget to clear DP */
	dp.clear();
	dp.resize(20);
	for(auto &vec_2d : dp)
		vec_2d.resize(max_sum, vector<long long>(2, -1));

	a.clear();
	while(num)
	{
		a.push_back(num%10);
		num /= 10;
	}
	reverse(a.begin(), a.end());

	return rec(0, 0, false);
}

vector<long long> waysToChooseSum(long long low, long long high)
{
	vector<long long> freq(max_sum, 0);

	for(int sum = 1; sum < max_sum; sum++)
	{
		req_sum = sum;
		freq[sum] += solve(high);
		freq[sum] -= solve(low - 1);
	}

	auto maximal_freq = *max_element(freq.begin(), freq.end());

	int cnt = 0;
	for(int sum = 1; sum < max_sum; sum++)
		if(freq[sum] == maximal_freq)
			cnt++;

	return {cnt, maximal_freq};
}

int main()
{
	long long low, high;
	cin >> low >> high;

	auto res = waysToChooseSum(low, high);
	for(auto ele : res)
		cout << ele << endl;

	return 0;
}



