#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &start, vector<int> &duration)
{
	int n = start.size();
	vector<int> finish = duration;

	// Add the duration  to get the end time
	for(int i = 0; i < n; i++)
		finish[i] += start[i];

	vector<pair<int, int>> fin_start;

	for(int i = 0; i < n; i++)
		fin_start.push_back(make_pair(finish[i], start[i]));
	
	// Sort according to finish time
	sort(fin_start.begin(), fin_start.end());

	int profit = 0;
	int last_act_end = -1;
	
	/* Greedily take activities according to least finish time */
	for(int i = 0; i < n; i++)
	{
		int s_time = fin_start[i].second;
		int e_time = fin_start[i].first;
		
		if( s_time >= last_act_end)
		{
			profit += 1;
			last_act_end = e_time;
		}
	}

	cout << profit << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> start(n), duration(n);

	for(auto &ele : start)
		cin >> ele;
	
	int fake;
	cin >> fake;

	for(auto &ele : duration)
		cin >> ele;

	solve(start, duration);
	return 0;
}
