#include<bits/stdc++.h>
using namespace std;

void peaceful_groups(vector<int> &a)
{
	int n = a.size();
	
	map<int, int> maxRight;
	for(int i = 0; i < n; i++)
		maxRight[a[i]] = i;

	vector<int> color(n, 0);

	int curr_c = 0;
	map<int, int> collection;
	for(int i = 0; i < n; i++)
	{
		color[i] = curr_c;

		collection[a[i]] = 1;
		if(maxRight[a[i]] == i)
			collection.erase(a[i]);

		if(collection.empty())
		{
			curr_c = not curr_c;
			continue;
		}
		


	}

	int i = 0, res = 0;
	curr_c = 0;
	while(i < n)
	{
		map<int, int> freq;
		for(; i < n and color[i] == curr_c; i++)
			freq[a[i]]++;

		int seg_size = 0, max_freq = 0;
		for(auto ele : freq)
		{
			seg_size += ele.second;
			max_freq = max(max_freq, ele.second);
		}

		res += (seg_size - max_freq);
		curr_c = not curr_c;
	}

	cout << res << endl;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	peaceful_groups(a);
	return 0;
}


