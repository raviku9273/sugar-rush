#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>
#define mp make_pair
typedef priority_queue<pll, vector<pll>, greater<pll>> minHeap;

/* Using a Deque would lead to TLE */
void load_balancing(vector<pll> &arr_load, int tot_servers)
{

	sort(arr_load.begin(), arr_load.end());

	/* Heap contains (first_free_time, server_num) */
	minHeap heap;
	
	/* Total Load can overflow */
	vector<long long> tot_load(tot_servers, 0);

	for(int i = 0; i < tot_servers; i++)
		heap.push(mp(0, i));


	for(int i = 0; i < arr_load.size(); i++)
	{
		auto time_now = arr_load[i].first;
		auto time_till = time_now + arr_load[i].second - 1;

		auto first_free_time = heap.top().first;
		auto first_free_server = heap.top().second;

		if(first_free_time > time_now)
			continue;

		heap.pop();

		tot_load[first_free_server] += arr_load[i].second;
		heap.push(mp(time_till, first_free_server));
	}
	
	auto maximal_load = *max_element(tot_load.begin(), tot_load.end());

	vector<int> res;
	for(int i = 0; i < tot_servers; i++)
		if(tot_load[i] == maximal_load)
			res.push_back(i);

	for(auto ele : res)
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
