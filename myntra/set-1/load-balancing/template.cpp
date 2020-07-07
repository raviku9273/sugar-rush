#include <bits/stdc++.h>
using namespace std;

vector<int> loadBalancing(int k, vector<int> arrival, vector<int> load)
{
}

int main()
{
	int tot_servers;
	cin >> tot_servers;

	int sz;
	cin >> sz;

	vector<int> arrival(sz);
	for(auto &ele : arrival)
		cin >> ele;

	cin >> sz;
	vector<int> load(sz);
	for(auto &ele : load)
		cin >> ele;

	auto res = loadBalancing(tot_servers, arrival, load);
	for(auto &ele : res)
		cout << ele << endl;

	return 0;
}
