#include<bits/stdc++.h>
using namespace std;

/* Be very careful with the implementation of Sieve */

int max_n = 1e6 + 2;
int a, b, k;

vector<int> prime;
void sieve()
{
	prime.resize(max_n, true);

	prime[0] = false; prime[1] = false;

	for(int num = 2; num < max_n; num++)
	{
		if(not prime[num])
			continue;

		for(int multiple = num*2; multiple < max_n; multiple += num)
			prime[multiple] = false;
	}
}

/* How many primes are there in a window of length 'len' starting at 'start' */
int get_prime_count(int start, int len)
{
	int finish = start + len - 1;

	if(start != 0)
		return prime[finish] - prime[start - 1];
	else
		return prime[finish];
}

bool valid(int len, int k)
{
	for(int start = a; start <= (b - len + 1); start++)
	{
		int prime_count = get_prime_count(start, len);

		if(prime_count < k)
			return false;
	}

	return true;
}

void solve(int k)
{
	int res = -1;

	int low = 1, high = b - a + 1;

	while(low <= high)
	{
		int mid = (low + high)/2;

		if(valid(mid, k))
		{
			res = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << res << endl;
}

int main()
{
	sieve();

	// Convert to prefix sum
	for(int i = 1; i < max_n; i++)
		prime[i] += prime[i - 1];

	cin >> a >> b >> k;

	solve(k);

	return 0;
}
