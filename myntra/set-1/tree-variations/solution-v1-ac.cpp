#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

class Tree
{
public:
	int vertex, max_val, cnt = 0;
	vector<vector<int>> adj;
	vector<int> a;
public:
	Tree(int vertex);
	void addEdge(int u, int v);
	bool check(int source, int parent, int min_ancestor);
};

Tree :: Tree(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
}

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Tree :: check(int source, int parent = -1, int min_ancestor = inf)
{
	if(a[source] > min_ancestor)
		return false;

	if(a[source] == max_val)
		cnt++;

	bool res = true;
	for(auto child : adj[source])
	{
		if(child == parent)
			continue;

		res = res and check(child, source, min(min_ancestor, a[source]));
	}

	return res;
}

int validRoots(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> a)
{
	Tree tree(g_nodes);

	for(int i = 0; i < g_from.size(); i++)
	{
		int x = g_from[i];
		int y = g_to[i];

		/* Why can't HackerRank stick to one-based indexing _--_ */
		/* x--; y--; */

		tree.addEdge(x, y);
	}

	tree.a = a;

	int max_val = -inf;
	for(auto &ele : tree.a)
		max_val = max(max_val, ele);

	tree.max_val = max_val;

	int source;
	for(int i = 0; i < a.size(); i++)
		if(a[i] == max_val)
			source = i;

	bool possible = tree.check(source);

	if(not possible)
		return 0;
	else
		return tree.cnt;
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
