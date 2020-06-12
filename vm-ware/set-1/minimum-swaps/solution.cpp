#include<bits/stdc++.h>
using namespace std;

class Solution
{
	int n;
	vector<int> a;
	vector<bool> visited;
public:
	void dfs(int source, int &seen);
	void solve();
	void input();
};

void Solution :: dfs(int source, int &seen)
{
	visited[source] = true;
	seen++;

	int child = n - a[source] - 1;
	
	if(not visited[child])
		dfs(child, seen);
}

void Solution :: solve()
{
	long long res = 0;
	for(int i = 0; i < n; i++)
	{
		if(not visited[a[i]])
		{
			int seen = 0;
			dfs(a[i], seen);
			res += seen - 1;
		}
	}

	cout << res << endl;
}

void Solution :: input()
{
	cin >> n;
	a.resize(n);
	visited.resize(n, false);

	for(auto &ele : a)
		cin >> ele, ele--;
}

int main()
{
	Solution sol;
	sol.input();
	sol.solve();

	return 0;
}
