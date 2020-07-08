#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>
#define mp make_pair

void load_balancing(vector<pll> &arr_load, int n)
{
	sort(arr_load.begin(), arr_load.end());

	vector<long long> tot_load(n);

	set<int> free_servers;
	set<pair<long long, int>> busy_servers;

	for(int i = 0; i < n; i++)
		free_servers.insert(i);

	int last_used_server = -1;

	for(auto ele : arr_load)
	{
		auto curr_time = ele.first;
		auto curr_load = ele.second;

		/* Free up all the servers */
		auto itr = busy_servers.begin();
		while(itr != busy_servers.end() and itr->first <= curr_time)
		{
			free_servers.insert(itr->second);
			itr = busy_servers.erase(itr);
		}
		
		if(free_servers.empty())
			continue;

		auto free_itr = free_servers.upper_bound(last_used_server);
		if(free_itr == free_servers.end())
			free_itr = free_servers.begin();

		last_used_server = *free_itr;
		tot_load[last_used_server] += curr_load;

		/* Remove it from free servers and add it to busy servers */
		free_servers.erase(free_itr);

		auto next_free_time = curr_time + curr_load - 1;
		busy_servers.insert(mp(next_free_time, last_used_server));
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
	return 0;
}
