#include<bits/stdc++.h>
using namespace std;

/* Fix  a weight 'w' and consider all edges of weight 'w'
 * In this unweighted-graph, find the maximal size of connected componenet
 * Find maximal pariwise product in the maximal connected components.
 */

const int max_weight = 100 + 1;
map<int, int> product_map;

class Graph
{
public:
	int vertex;
	vector<vector<vector<int>>> adj;
	vector<int> visited;
public:
	Graph(int vertex);
	void addEdge(int u, int v, int w);
	void fixed_weight_dfs(int source, vector<int> &collection, int w);
	void fixed_weight_dfs_wrapper(int w);
};

Graph :: Graph(int vertex)
{
	this->vertex = vertex;
	adj.resize(max_weight, vector<vector<int>>(vertex));
}

void Graph :: addEdge(int u, int v, int w)
{
	adj[w][u].push_back(v);
	adj[w][v].push_back(u);
}

void Graph :: fixed_weight_dfs(int source, vector<int> &collection, int w)
{
	collection.push_back(source);
	visited[source] = true;

	for(auto child : adj[w][source])
		if(not visited[child])
			fixed_weight_dfs(child, collection, w);

}
void Graph :: fixed_weight_dfs_wrapper(int w)
{
	vector<vector<int>> cc_info;

	visited.assign(vertex, false);
	for(int i = 0; i < vertex; i++)
	{
		if(not visited[i])
		{
			vector<int> collection;
			fixed_weight_dfs(i, collection, w);
			cc_info.push_back(collection);
		}
	}

	int max_size = 0;
	for(auto &single_cc : cc_info)
		max_size = max(max_size, (int)single_cc.size());

	int res = 0;
	for(auto &single_cc : cc_info)
	{
		if((int)single_cc.size() != max_size)
			continue;
		
		for(int i = 0; i < single_cc.size(); i++)
			for(int j = i + 1; j < single_cc.size(); j++)
				res = max(res, (single_cc[i] + 1)*(single_cc[j] + 1));
	}

	product_map[max_size] = max(product_map[max_size], res);
}

int countCandies(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight)
{
	int vertex = friends_nodes;
	int edges = friends_from.size();

	Graph graph(vertex);

	for(int i = 0; i < edges; i++)
	{
		int u = friends_from[i];
		int v = friends_to[i];
		int w = friends_weight[i];

		u--; v--;
		graph.addEdge(u, v, w);
	}

	for(int w = 1; w < max_weight; w++)
		graph.fixed_weight_dfs_wrapper(w);

	int ans = 0;

	ans = product_map.rbegin()->second;

	assert(ans > 0);
	return ans;
}

int main()
{
	int friends_nodes;
	cin >> friends_nodes;

	int dim;
	cin >> dim;

	vector<int> friends_from(dim);
	for(auto &ele : friends_from)
		cin >> ele;

	cin >> dim;
	vector<int> friends_to(dim);
	for(auto &ele : friends_to)
		cin >> ele;

	cin >> dim;
	vector<int> friends_weight(dim);
	for(auto &ele : friends_weight)
		cin >> ele;

	cout << countCandies(friends_nodes, friends_from, friends_to, friends_weight);
	cout << endl;
	return 0;
}

/* Note to self : Refer version-1 to find out why it won't work without map
 * See gen-man-2.txt for a tricky test-case */
