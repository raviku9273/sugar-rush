#include<bits/stdc++.h>
using namespace std;

int get_sum(vector<int> &prefix, int left, int right)
{
	if(left != 0)
		return prefix[right] - prefix[left - 1];
	else
		return prefix[right];
}

/* Maximum length of a subarray which has sum <= k */
int Arbitrary_Shopping(vector<int> &a, int k)
{
	int n = a.size();
	
	vector<int> prefix = a;
	for(int i = 1; i < n; i++)
		prefix[i] += prefix[i-1];
	
	int res = 0;
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if(get_sum(prefix, i, j) <= k)
				res = max(res, j - i + 1);
	
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
