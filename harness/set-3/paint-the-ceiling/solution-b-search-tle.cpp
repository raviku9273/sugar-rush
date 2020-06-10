#include<bits/stdc++.h>
using namespace std;

/* Bug : Promote start to long long or else array elements would overflow */
long long variantsCount(int n, int start, int k, int b, int mod, long long maxArea)
{
	/* Product can overflow. Take care */
	vector<long long> a(n);
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
	int ind;
	for(auto ele : a)
	{
		if( ele > maxArea)
			continue;

		key = (maxArea/ele);

		ind = upper_bound(a.begin(), a.end(), key) - a.begin();
		ind--;
		
		if(ind < 0)
			continue;
		
		res += (ind + 1);
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

