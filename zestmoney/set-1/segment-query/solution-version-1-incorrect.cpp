#include<bits/stdc++.h>
using namespace std;

vector<long long> a, prefix;
double p;

long long get_sum(int left, int right)
{
	if(left != 0)
		return prefix[right] - prefix[left - 1];
	else
		return prefix[right];
}

void query(int left, int right, int day)
{
	double res = pow(1 - p, day - 1);
	res *= p;

	res *= get_sum(left, right);

	/* Doubt */
	long long roundoff = round(res);
	
	cout << roundoff << endl;
}

void solve()
{
	int n;
	cin >> n;

	a.resize(n);
	for(auto &ele : a)
		cin >> ele;

	prefix = a;
	for(int i = 1; i < n; i++)
		prefix[i] += prefix[i - 1];

	int percentage;
	cin >> percentage;

	p = 1.00*percentage/100;

	int q;
	cin >> q;

	vector<int> days(q);
	for(auto &ele : days)
		cin >> ele;

	cin >> q;
	vector<int> left(q);
	for(auto &ele : left)
		cin >> ele, ele--;

	cin >> q;
	vector<int> right(q);
	for(auto &ele : right)
		cin >> ele, ele--;

	
	for(int i = 0; i < q; i++)
		query(left[i], right[i], days[i]);
}

int main()
{
	solve();
	return 0;
}
