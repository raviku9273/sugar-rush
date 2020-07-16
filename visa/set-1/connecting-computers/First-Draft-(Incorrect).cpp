#include<bits/stdc++.h>
using namespace std;

/* This solution is wrong. This is an undirected graph, so counting 
 * the number of edges is not easy. Some edges would be counted twice, but other's won't.
 * (This is because we represent an edge as (u --> v) and (v --> u), so we overcalculate back edges.
 * All this is not needed. See model solution!
 */

class Graph
{
public:
	int vertex, back_edges = 0;
	vector<vector<int>> adj;
	vector<bool> visited;
	vector<int> color;
public:
	Graph(int vertex);
	void addEdge(int u, int v);
	void dfs(int source, int parent, int current_color);
	int min_edge_transfer();
};

Graph :: Graph(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	visited.resize(vertex, false);
	color.resize(vertex);
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph :: dfs(int source, int parent, int current_color)
{
	visited[source] = true;
	color[source] = current_color;

	for(auto child : adj[source])
	{
		if(child == parent)
			continue;

		if(not visited[child])
			dfs(child, source, current_color);
		else
			back_edges++;
	}
}

int Graph :: min_edge_transfer()
{
	int current_color = 0;
	for(int i = 0; i < vertex; i++)
	{
		if(not visited[i])
		{
			current_color++;
			dfs(i, -1, current_color);
		}
	}

	int components = current_color;
	if(back_edges >= (components - 1))
		return (components - 1);
	else
		return -1;
}

void test()
{
	int vertex;
	cin >> vertex;
	
	Graph graph(vertex);

	int edges;
	cin >> edges;

	for(int i = 0; i < edges; i++)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;

		graph.addEdge(u, v);
	}

	cout << graph.min_edge_transfer() << endl;
}

int main()
{
	test();
	return 0;
}
