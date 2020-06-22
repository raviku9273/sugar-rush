#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
	int vertex;
	vector<vector<int>> adj;
	vector<int> dp_inc, dp_exc, dp_subtree;
public:
	Tree(int vertex);
	void addEdge(int u, int v);
	void dfs(int source, int parent);
};


/* dp_inc[source] is min-vertex-cover when you have to include 'source'
 * dp_exc[source] is min-vertex-cover when you have to exclude 'source'
 * dp_subtree[source] is min-vertex-cover when you have no restrictions on 'source'.
 */

Tree :: Tree(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	dp_inc.resize(vertex), dp_exc.resize(vertex);
	dp_subtree.resize(vertex);
}

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Tree :: dfs(int source, int parent)
{
	dp_inc[source] = 1;
	dp_exc[source] = 0;

	for(auto child : adj[source])
	{
		if(child == parent)
			continue;

		dfs(child, source);

		dp_inc[source] += dp_subtree[child];
		dp_exc[source] += dp_inc[child];
	}

	dp_subtree[source] = min(dp_inc[source], dp_exc[source]);
}

/*********************** Template Begins ****************************/

int hospital(int city_nodes, vector<int> city_from, vector<int> city_to)
{
	Tree tree(city_nodes);

	for(int i = 0; i < city_from.size(); i++)
	{
		city_from[i]--; city_to[i]--;
		tree.addEdge(city_from[i], city_to[i]);
	}

	tree.dfs(0, -1);
	return tree.dp_subtree[0];
}

/*********************** Template Ends ****************************/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int city_nodes, edges;
	cin >> city_nodes >> edges;

	vector<int> city_from(edges), city_to(edges);

	for(int i = 0; i < edges; i++)
		cin >> city_from[i] >> city_to[i];

	cout << hospital(city_nodes, city_from, city_to) << endl;
	return 0;
}
