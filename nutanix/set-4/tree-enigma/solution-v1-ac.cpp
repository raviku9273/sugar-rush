#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

class Tree
{
public:
	int vertex;
	vector<vector<int>> adj;
	vector<vector<int>> memo;
	vector<int> color, true_color;
public:
	Tree(int vertex);
	void addEdge(int u, int v);
	int dfs(int source, int parent, int inv_fac);
};

Tree :: Tree(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	memo.resize(vertex, vector<int>(2, -1));
	color.resize(vertex);
	true_color.resize(vertex);
}

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int Tree :: dfs(int source, int parent, int inv_fac)
{
	if(memo[source][inv_fac] != -1)
		return memo[source][inv_fac];

	int source_val = color[source] xor inv_fac;
	
	int res = inf;

	/* Root is of true color */
	if(source_val == true_color[source])
	{
		int cost = 0;

		// Don't invert
		for(auto child : adj[source])
		{
			if(child == parent)
				continue;

			cost += dfs(child, source, inv_fac);
		}

		res = min(res, cost);

		// Invert entire subtree, and then invert only root
		cost = 2;
		for(auto child : adj[source])
		{
			if(child == parent)
				continue;

			cost += dfs(child, source, inv_fac xor 1);
		}

		res = min(res, cost);
	}

	// Root is inverted
	if(source_val != true_color[source])
	{
		// Invert just the root
		int cost = 1;
		for(auto child : adj[source])
		{
			if(child == parent)
				continue;

			cost += dfs(child, source, inv_fac);
		}
		
		res = min(res, cost);

		// Invert the entire subtree
		cost = 1;
		for(auto child : adj[source])
		{
			if(child == parent)
				continue;

			cost += dfs(child, source, inv_fac xor 1);
		}

		res = min(res, cost);
	}

	memo[source][inv_fac] = res;
	return res;
}

void solve()
{
	int n;
	cin >> n;

	Tree tree(n);
	for(int i = 0; i < (n-1); i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;

		tree.addEdge(u, v);
	}

	for(auto &ele : tree.color)
		cin >> ele;

	for(auto &ele : tree.true_color)
		cin >> ele;

	cout << tree.dfs(0, -1, 0) << endl;
}

int main()
{
	solve();
	return 0;
}
