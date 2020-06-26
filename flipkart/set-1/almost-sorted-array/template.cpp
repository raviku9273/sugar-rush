#include <bits/stdc++.h>
using namespace std;

int almost_sorted(vector<int> &a)
{
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	cout << almost_sorted(a) << endl;
	return 0;
}


