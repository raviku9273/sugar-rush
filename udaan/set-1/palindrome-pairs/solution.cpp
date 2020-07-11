#include<bits/stdc++.h>
using namespace std;

void solve(vector<string> &collection)
{
	vector<int> a;
	for(auto str : collection)
	{
		int mask = 0;
		for(auto letter : str)
		{
			mask = mask xor (1 << (letter - 'a'));
		}

		a.push_back(mask);
	}
	
	map<int, int> myMap;
	long long res = 0;

	for(auto mask : a)
	{
		int target = 0;
		res += myMap[mask xor target];

		for(int letter = 'a'; letter <= 'z'; letter++)
		{
			target = 1 << (letter - 'a');
			res += myMap[mask xor target];
		}

		myMap[mask]++;
	}

	cout << res << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<string> collection(n);
	for(auto &str : collection)
		cin >> str;

	solve(collection);

	return 0;
}
 
