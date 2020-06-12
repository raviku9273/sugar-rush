#include<bits/stdc++.h>
using namespace std;

void document_chunking()
{
	long long total_packets;
	cin >> total_packets;

	int n, fake;
	cin >> n >> fake;

	vector<pair<long long, long long>> a(n);

	for(auto &ele : a)
		cin >> ele.first >> ele.second;
	
	/* 2 Sentinels would make our lives easier */
	a.push_back(make_pair(0, 0));
	a.push_back(make_pair(total_packets + 1, total_packets + 1));

	sort(a.begin(), a.end());
	
	long long res = 0;
	for(int i = 1; i < a.size(); i++)
	{
		/* distance between (a, b) */
		auto curr_gap = a[i].first - a[i - 1].second - 1;
		res += __builtin_popcountll(curr_gap);
	}

	cout << res << endl;
}

int main()
{
	document_chunking();
	return 0;
}
