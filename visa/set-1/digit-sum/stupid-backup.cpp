#include <bits/stdc++.h>
using namespace std;

int get_sum(long long num)
{
	int sum = 0;
	while(num)
	{
		sum += num%10;
		num /= 10;
	}

	return sum;
}

vector<long long> waysToChooseSum(long long low, long long high)
{
	map<int, long long> freq;
	for(auto num = low; num <= high; num++)
		freq[get_sum(num)]++;

	long long maximal_freq = 0;
	for(auto ele : freq)
		maximal_freq = max(maximal_freq, ele.second);

	int cnt = 0;
	for(auto ele : freq)
		if(ele.second == maximal_freq)
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



