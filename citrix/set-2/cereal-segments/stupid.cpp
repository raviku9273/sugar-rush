#include<bits/stdc++.h>
using namespace std;

void sliding_window_min(vector<int> &a, int k)
{
	int n = a.size();

	multiset<int> mset;

	for(int i = 0; i < k; i++)
		mset.insert(a[i]);

	int res = INT_MIN;

	res = max(res, *mset.begin());

	for(int i = k; i < n; i++)
	{
		mset.erase(mset.find(a[i - k]));
		mset.insert(a[i]);

		res = max(res, *mset.begin());
	}

	cout << res << endl;
}

int main()
{
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
