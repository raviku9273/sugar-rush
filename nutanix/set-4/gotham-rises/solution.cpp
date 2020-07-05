#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int vertex;
	vector<bool> visited;
	vector<vector<int>> adj;
public:
	Graph(int vertex);
	void addEdge(int u, int v);
	void dfs(int source);
	int dfs_wrapper();
};

Graph :: Graph(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph :: dfs(int source)
{
	visited[source] = true;

	for(auto child : adj[source])
		if(not visited[child])
			dfs(child);
}

int Graph :: dfs_wrapper()
{
	visited.assign(vertex, false);

	int cc_count = 0;
	
	for(int i = 0; i < vertex; i++)
	{
		if(not visited[i])
		{
			dfs(i);
			cc_count++;
		}
	}

	return cc_count;
}

void solve()
{
	int vertex, edges;
	long long vertex_cost, edge_cost;

	cin >> vertex >> edges;
	cin >> vertex_cost >> edge_cost;

	Graph graph(vertex);
	for(int i = 0; i < edges; i++)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;

		graph.addEdge(x, y);
	}

	if(vertex_cost <= edge_cost)
	{
		cout << vertex_cost*vertex << endl;
	}
	else
	{
		int cc_count = graph.dfs_wrapper();
		auto res = vertex_cost*cc_count;
		res += (vertex - cc_count)*edge_cost;

		cout << res << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
		solve();

	return 0;
}

