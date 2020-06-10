#include<bits/stdc++.h>
using namespace std;

long Brute(int n, int start, int k, int b, int mod, long long maxArea)
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
	
	long cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			// Don't check a[i]*a[j]. Overflows
			if(a[i] <= maxArea/a[j])
				cnt += 1;
		}
	}
	
	return cnt;
}

int main()
{
	int n, start, k, b, mod;
	long long maxArea;
	
	cin >> n >> start >> k >> b >> mod >> maxArea;
	cout << Brute(n, start, k, b, mod, maxArea) << endl;

	return 0;
}

