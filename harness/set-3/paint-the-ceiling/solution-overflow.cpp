#include<bits/stdc++.h>
using namespace std;

/* Bug : Promote start to long long or else array elements would overflow */
long long variantsCount(int n, int start, int k, int b, int mod, long long maxArea)
{
	/* Product can overflow. Take care */
	vector<int> a(n);
	a[0] = start;
	long long prev = start;

	for(int i = 1; i < n; i++)
	{
		a[i] = ( (1LL*k*prev) + b)%mod + 1 + prev;
		prev = a[i];
	}

	// Sort the array to apply binary search
	/* Here's the catch. It's already sorted. */
	/* Not possible to sort with given constraints */
	/* sort(a.begin(), a.end()); */
	
	long long res = 0;
	long long key;
	
	int left = 0, right = n - 1;
	while(left <= right)
	{
		key = 1LL*a[left]*a[right];

		if(key > maxArea)
		{
			right--;
		}
		else
		{
			// Every pair is counted twice, except (left, left)
			res += 1LL*2*(right - left) + 1;
			left++;
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

