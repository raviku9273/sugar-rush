#include<bits/stdc++.h>
using namespace std;

/* Things in favour : Array does not contain negative elements */

/* Maximum length of a subarray which has sum <= k */
int Arbitrary_Shopping(vector<int> &a, int k)
{
	int n = a.size();
	int sum = 0;
	int res = 0;

	int left = 0, right = 0;
	while(left <= right and right < n)
	{
		if(a[right] > k)
		{
			right++;
			left = right;
			sum = 0;
			continue;
		}
	
		sum += a[right];
		
		/* Left can never cross Right here, as a[right] <= k) */
		while(sum > k)
		{
			sum -= a[left];
			left++;
		}

		res = max(res, right - left + 1);
		right++;
	}

	return res;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	int k;
	cin >> k;

	cout << Arbitrary_Shopping(a, k) << endl;
	return 0;
}
