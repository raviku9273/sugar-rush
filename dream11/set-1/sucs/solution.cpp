#include <bits/stdc++.h>
using namespace std;

int shortest_unsorted(vector<int> &a)
{
	int n = a.size();

	vector<int> minRight(n), maxLeft(n);

	minRight[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--)
		minRight[i] = min(a[i], minRight[i + 1]);

	maxLeft[0] = a[0];
	for(int i = 1; i < n; i++)
		maxLeft[i] = max(a[i], maxLeft[i - 1]);

	int left_mismatch = -1, right_mismatch = n;

	for(int i = n - 1; i >= 0; i--)
		if(minRight[i] != a[i])
			left_mismatch = i;

	for(int i = 0; i < n; i++)
		if(maxLeft[i] != a[i])
			right_mismatch = i;

	if(left_mismatch == -1 or right_mismatch == n)
		return 0;

	return (right_mismatch - left_mismatch + 1);
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for(auto &ele : a)
		scanf("%d", &ele);

	int res = shortest_unsorted(a);
	printf("%d\n", res);

	return 0;
}
