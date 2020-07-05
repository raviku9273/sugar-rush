#include <bits/stdc++.h>
using namespace std;

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
	int dfs(int source, int parent, int inv);
};

Tree :: Tree(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	memo.resize(vertex, vector<int>(2, -1));
	color.resize(vertex); true_color.resize(vertex);
}

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int Tree :: dfs(int source = 0, int parent = -1, int inv = 0)
{
	if(memo[source][inv] != -1)
		return memo[source][inv];

	int curr_color = color[source] xor inv;
	
	int cost_subtree_inv = 0, cost_norm = 0;

	for(auto child : adj[source])
	{
		if(child == parent)
			continue;

		/* Invert entire subtree */
		cost_subtree_inv += dfs(child, source, inv xor 1);

		/* Don't invert the subtree */
		cost_norm += dfs(child, source, inv);
	}

	int res;
	if(curr_color == true_color[source])
		res = min(cost_norm, 1 + cost_subtree_inv + 1);
	else
		res = min(1 + cost_norm, 1 + cost_subtree_inv);

	memo[source][inv] = res;
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

	cout << tree.dfs() << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}
