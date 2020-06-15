#include<bits/stdc++.h>
using namespace std;

void restock(vector<long long> &a, long long target)
{
	int n = a.size();

	for(int i = 0; i < n; i++)
	{
		if(target <= 0)
			break;

		target -= a[i];
	}

	cout << abs(target) << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<long long> a(n);
	for(auto &ele : a)
		cin >> ele;

	long long target;
	cin >> target;

	restock(a, target);
	return 0;
}
