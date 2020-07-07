#include <bits/stdc++.h>
using namespace std;

int validRoots(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> values)
{
}

int main()
{
	int g_nodes, edges;
	cin >> g_nodes >> edges;

	vector<int> g_from(edges), g_to(edges);
	
	for(int i = 0; i < edges; i++)
		cin >> g_from[i] >> g_to[i];

	cin >> g_nodes;
	vector<int> values(g_nodes);
	for(auto &ele : values)
		cin >> ele;

	auto res = validRoots(g_nodes, g_from, g_to, values);
	cout << res << endl;

	return 0;
}
