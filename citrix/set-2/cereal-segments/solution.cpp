#include<bits/stdc++.h>
using namespace std;

void sliding_window_min(vector<int> &a, int k)
{
	int n = a.size();

	deque<int> dq;

	// Fill the first window manually
	for(int i = 0; i < k; i++)
	{
		while(not dq.empty() and a[dq.back()] >= a[i])
			dq.pop_back();

		dq.push_back(i);
	}

	int res = INT_MIN;

	// Answer for the first window
	res = max(res, a[dq.front()]);

	for(int i = k; i < n; i++)
	{
		while(not dq.empty() and a[dq.back()] >= a[i])
			dq.pop_back();

		dq.push_back(i);

		if(dq.front() == i - k)
			dq.pop_front();

		// Result for the next window
		res = max(res, a[dq.front()]);
	}

	cout << res << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;


	sliding_window_min(a, k);
	return 0;
}
