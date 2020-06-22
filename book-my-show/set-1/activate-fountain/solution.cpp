#include <bits/stdc++.h>
using namespace std;

/*********************** Template begins ****************************/

/* Return an integer denoting the minimum number of fountains that must be activated */
int fountainActivation(vector<int> &a)
{
	int n = a.size();

	vector<int> maxRight(n);

	/* maxRight[left] is the maximum range of any fountain whose left
	 * end starts at 'left'
	 */

	for(int i = 0; i < n; i++)
	{
		int left = max(i - a[i], 0);
		int right = min(i + a[i], n - 1);
		maxRight[left] = max(maxRight[left], right);
	}

	int current_blockage = maxRight[0] + 1;
	int next_blockage, fountains = 1;

	for(int i = 0; i < n; i++)
	{
		next_blockage = max(next_blockage, maxRight[i]);

		if(i == current_blockage)
		{
			fountains++;
			current_blockage = next_blockage + 1;
		}
	}

	return fountains;
}

/*********************** Template Ends ****************************/

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	cout << fountainActivation(a) << endl;
	return 0;
}
