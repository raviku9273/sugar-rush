#include<bits/stdc++.h>
using namespace std;

int n, percentage, max_size;
vector<long long> a;
vector<vector<long long>> remain;

/* The amount of leaves that remain after each day for the tree at index */
void compute_remain(int index, vector<long long> &remain)
{
	auto leaves_remain = a[index];
	remain.push_back(leaves_remain);

	while(true)
	{
		/* Shitty Problem Statement :( */
		long long leaves_fallen = ceil((long double)1.0*leaves_remain*percentage/100);
		leaves_remain -= leaves_fallen;


		assert(leaves_remain >= 0);
		remain.push_back(leaves_remain);

		int curr_size = remain.size();

		if(remain[curr_size - 1] == remain[curr_size - 2])
			break;
	}
}

/* remain[i][day] represents the number of leaves remaining on the i-th tree on day 'day' */
void populate_dp()
{
	max_size = 0;

	for(int i = 0; i < n; i++)
	{
		compute_remain(i, remain[i]);
		max_size = max(max_size, (int)(remain[i].size()));
	}

	for(int i = 0; i < n; i++)
		remain[i].resize(max_size, remain[i].back());

	/* Convert each column to prefix-sum */
	for(int day = 0; day < max_size; day++)
	{
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
				continue;

			remain[i][day] += remain[i - 1][day];
		}
	}
}

/* What is the total number of leaves fallen between (left, right) TILL day 'day' */
long long query(int left, int right, int day)
{
	long long res = 0;

	if(left != 0)
	{
		res  = a[right] - a[left - 1];
		res -= remain[right][day] - remain[left - 1][day];
	}
	else
	{
		res  = a[right];
		res -= remain[right][day];
	}

	return res;
}

void solve(vector<int> &days, vector<int> &left, vector<int> &right)
{
	populate_dp();

	/* Convert 'a' to a prefix-sum array */
	for(int i = 1; i < n; i++)
		a[i] += a[i - 1];

	for(int i = 0; i < days.size(); i++)
	{
		int current_day = min(days[i], max_size - 1);

		auto res = query(left[i], right[i], current_day);
		res -= query(left[i], right[i], current_day - 1);

		assert(res >= 0);
		cout << res << endl;
	}
}

int main()
{
	cin >> n;

	a.resize(n);
	for(auto &ele : a)
		cin >> ele;

	remain.resize(n);
	cin >> percentage;

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

	solve(days, left, right);
	return 0;
}
