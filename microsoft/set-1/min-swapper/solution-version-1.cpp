#include <bits/stdc++.h>
using namespace std;

int min_swapper(string str)
{
	int n = str.length();
	
	if(n < 2)
		return 0;

	map<char, int> freq, first_occ, last_occ;
	
	for(int i = 0; i < n; i++)
		last_occ[str[i]] = i, freq[str[i]]++;

	for(int i = n - 1; i >= 0; i--)
		first_occ[str[i]] = i;

	int odd_count = 0;
	for(char ele = 'a'; ele <= 'z'; ele++)
		if(freq.count(ele) and freq[ele]%2 != 0)
			odd_count++;

	if(odd_count > 1)
		return -1;

	int res = INT_MAX;
	for(char ele = 'a'; ele <= 'z'; ele++)
	{
		if(freq.count(ele) and freq[ele] != 1)
		{
			int cost = 0;
			cost += abs(0 - first_occ[ele]);
			cost += abs(n - 1 - last_occ[ele]);

			string new_str = "";
			for(int i = 0; i < n; i++)
			{
				if(i == first_occ[ele] or i == last_occ[ele])
					continue;

				new_str += str[i];
			}
			
			cost += min_swapper(new_str);
			res = min(res, cost);
		}
	}
	return res;
}

int main()
{
	string str;
	cin >> str;

	while(str != "0")
	{
		int res = min_swapper(str);
		if(res == -1)
			cout << "Impossible" << endl;
		else
			cout << res << endl;

		cin >> str;
	}
}
