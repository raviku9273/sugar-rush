#include<bits/stdc++.h>
using namespace std;

int minOperations(int comp_nodes, vector<int> comp_from, vector<int> comp_to)
{
}

int main()
{
	int comp_nodes;
	cin >> comp_nodes;

	int edges;
	cin >> edges;

	vector<int> comp_from(edges), comp_to(edges);

	for(int i = 0; i < edges; i++)
		cin >> comp_from[i] >> comp_to[i];

	int res = minOperations(comp_nodes, comp_from, comp_to);
	cerr << res << endl;
	cout << res << endl;

	return 0;
}
