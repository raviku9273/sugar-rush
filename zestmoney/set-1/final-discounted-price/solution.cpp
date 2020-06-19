#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &a)
{
	int n = a.size();

	stack<int> stk;
	long long res = 0;
	
	vector<int> full_price;

	for(int i = n - 1; i >= 0; i--)
	{
		while(not stk.empty() and a[stk.top()] > a[i])
			stk.pop();

		if(not stk.empty())
			res += a[i] - a[stk.top()];
		else
			res += a[i], full_price.push_back(i);

		stk.push(i);
	}

	cout << res << endl;
	
	reverse(full_price.begin(), full_price.end());

	for(auto ele : full_price)
		cout << ele << " ";

	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	solve(a);
	return 0;
}
