#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>

void load_balancing(vector<pll> &arr_load, int n)
{
	sort(arr_load.begin(), arr_load.end());

	vector<long long> a(n), tot_load(n), free_time(n);

	int i_free = 0;
	int nxt;
	for(auto ele : arr_load)
	{
		auto curr_time = ele.first;
		auto curr_load = ele.second;

		bool all_busy = true;
		for(int j = i_free; j < i_free + n; j++)
		{
			int i = j%n;
			if(free_time[i] <= curr_time)
			{
				all_busy = false;
				tot_load[i] += curr_load;
				free_time[i] = curr_time + curr_load - 1;
				nxt = (i + 1)%n;
				break;
			}
		}

		if(all_busy)
			continue;

		i_free = nxt;
	}

	auto maximal = *max_element(tot_load.begin(), tot_load.end());

	vector<int> res;
	for(int i = 0; i < n; i++)
		if(tot_load[i] == maximal)
			res.push_back(i);

	for(auto &ele : res)
		cout << ele + 1 << endl;
}

int main()
{
	int tot_servers;
	cin >> tot_servers;

	int sz;
	cin >> sz;

	vector<pll> arr_load(sz);
	for(auto &ele : arr_load)
		cin >> ele.first;

	cin >> sz;
	for(auto &ele : arr_load)
		cin >> ele.second;

	load_balancing(arr_load, tot_servers);

	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 
	return 0;
}
