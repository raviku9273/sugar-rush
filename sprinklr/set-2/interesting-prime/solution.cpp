#include<bits/stdc++.h>
using namespace std;

/* Be very careful with the implementation of Sieve */

int max_n = 1e6 + 2;

vector<bool> prime;
vector<int> collection;

void sieve()
{
	prime.assign(max_n, true);

	prime[0] = false; prime[1] = false;

	for(int num = 2; num < max_n; num++)
	{
		if(not prime[num])
			continue;

		for(int multiple = num*2; multiple < max_n; multiple += num)
			prime[multiple] = false;
	}
}

void pre_compute()
{
	for(long long a = 1; a <= 1000; a++)
	{
		for(long long b = 1; b <= 100; b++)
		{
			auto sum = a*a + b*b*b*b;
			if(sum < max_n and prime[sum])
				collection.push_back(sum);
		}
	}

	set<int> sort_remove_dup;
	for(auto &ele : collection)
		sort_remove_dup.insert(ele);

	collection.clear();
	for(auto &ele : sort_remove_dup)
		collection.push_back(ele);
}

void solve()
{
	int n;
	cin >> n;

	int ans = upper_bound(collection.begin(), collection.end(), n) - collection.begin();
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	sieve();
	pre_compute();

	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
		solve();

	return 0;
}
