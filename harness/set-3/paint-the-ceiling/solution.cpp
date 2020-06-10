#include<bits/stdc++.h>
using namespace std;

long long variantsCount(int n, int start, int k, int b, int mod, long long maxArea)
{
	/* Catch 1 : Numbers can become too big. Use long long */
	vector<long long> a(n);
	a[0] = start;

	for(int i = 1; i < n; i++)
	{
		/* Catch 2 : Product might overflow. Take mod at the beginning */
		long long res = a[i - 1] % mod;
		res = (res*k)%mod;
		res = (res + b)%mod;

		a[i] = res + 1 + a[i - 1];
	}

	// Sort the array to apply binary search
	/* Here's the catch 3. It's already sorted. */
	/* Not possible to sort with given constraints */
	/* sort(a.begin(), a.end()); */
	
	long long key, res = 0;
	
	int left = 0, right = n - 1;
	while(left <= right)
	{
		// Catch 4 : Never multiply big integers
		/* key = a[left]*a[right]; */

		if(a[left] <= maxArea/a[right])
		{
			// Every pair is counted twice, except (left, left)
			res += 1LL*2*(right - left) + 1;
			left++;
		}
		else
		{
			right--;
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, start, k, b, mod;
	long long maxArea;
	
	cin >> n >> start >> k >> b >> mod >> maxArea;
	cout << variantsCount(n, start, k, b, mod, maxArea) << endl;

	return 0;
}

