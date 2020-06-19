#include<bits/stdc++.h>
using namespace std;

const int max_day = 70 + 1;
int n, percentage;
vector<long long> a;
vector<vector<long long>> remain;

/* The amount of leaves that remain after each day for the tree at index */
void compute_remain(int index, vector<long long> &remain)
{
	auto leaves_remain = a[index];
	remain.push_back(leaves_remain);

	while(leaves_remain)
	{
		/* Shitty Problem Statement :( */
		auto leaves_fallen = leaves_remain*percentage;

		if(leaves_fallen % 100 == 0)
			leaves_fallen /= 100;
		else
			leaves_fallen = leaves_fallen/100 + 1;

		leaves_remain -= leaves_fallen;


		remain.push_back(leaves_remain);
	}
}

/* remain[i][day] represents the number of leaves remaining on the i-th tree on day 'day' */
void populate_dp()
{
	for(int i = 0; i < n; i++)
	{
		compute_remain(i, remain[i]);
		remain[i].resize(max_day);
	}

	/* Convert each column to prefix-sum */
	for(int day = 0; day < max_day; day++)
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
		/* Total number of leaves - total_remaining */
		res  = remain[right][0] - remain[left - 1][0];
		res -= remain[right][day] - remain[left - 1][day];
	}
	else
	{
		res  = remain[right][0];
		res -= remain[right][day];
	}

	return res;
}

void solve(vector<int> &days, vector<int> &left, vector<int> &right)
{
	populate_dp();

	for(int i = 0; i < days.size(); i++)
	{
		int current_day = min(days[i], max_day - 1);

		auto res = query(left[i], right[i], current_day);
		res -= query(left[i], right[i], current_day - 1);

		cout << res << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

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
