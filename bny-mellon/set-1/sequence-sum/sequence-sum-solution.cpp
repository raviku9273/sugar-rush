#include<bits/stdc++.h>
using namespace std;

long long get_sum(long long start, long long len)
{
	long long res = start*len;
	res += len*(len - 1)/2;

	return res;
}

int main()
{
	long long i, j, k, len, res;
	cin >> i >> j >> k;

	len = j - i + 1;
	res = get_sum(i, len);

	len = j - k;
	res += get_sum(k, len);

	cout << res << endl;
}
