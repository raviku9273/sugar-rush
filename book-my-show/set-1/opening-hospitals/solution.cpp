#include <bits/stdc++.h>
using namespace std;

const int hosp = 1;
const int covered = 2;
const int uncovered = 3;

class Tree
{
public:
	int vertex, res = 0;
	vector<vector<int>> adj;
	vector<int> state;
public:
	Tree(int vertex);
	void addEdge(int u, int v);
	void dfs(int source, int parent);
};

Tree :: Tree(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	state.resize(vertex, uncovered);
}

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Tree :: dfs(int source, int parent)
{
	bool child_uncovered = false;
	bool child_has_hosp = false;

	for(auto child : adj[source])
	{
		if(child == parent)
			continue;

		dfs(child, source);

		if(state[child] == uncovered)
			child_uncovered = true;

		if(state[child] == hosp)
			child_has_hosp = true;
	}

	if(child_uncovered)
	{
		state[source] = hosp; res++;
	}
	else if(child_has_hosp)
	{
		state[source] = covered;
	}
	else
	{
		state[source] = uncovered;
	}
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

	if(tree.state[0] == uncovered)
		tree.res = tree.res + 1;

	return tree.res;
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
