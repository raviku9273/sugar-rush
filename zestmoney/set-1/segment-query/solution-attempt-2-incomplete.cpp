#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> compute_remain(long long leaves_remain, int percentage)
{
	vector<int> remain;

	remain.push_back(leaves_remain);

	while(true)
	{
		long long leaves_fallen = round(1.0*leaves_remain*percentage/100);
		leaves_remain -= leaves_fallen;

		assert(leaves_remain >= 0);
		remain.push_back(leaves_remain);

		int curr_size = remain.size();

		if(remain[curr_size - 1] == remain[curr_size - 2])
			break;
	}

	return remain;
}

void compute_column_sum()
{
	int max_size = 0;

	for(int i = 0; i < n; i++)
		max_size = max(max_size, (int)(record[i].size()));

	for(int i = 0; i < n; i++)
	{
		auto &vec = record[i];

		whille((int)(vec.size()) != max_size())
			vec.push_back(vec.back());
	}

	/* col[day] is a vector of size 'n' containing the number of
	 * leaves remaining on each tree on the 'day' day
	 */

	for(int day = 0; day < max_size; day++)
	{
	
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
	return 0;
}
