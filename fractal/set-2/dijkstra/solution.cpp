#include <bits/stdc++.h>
using namespace std;

/* It's gonna be a long journey. Let's make things more concise */
#define mp make_pair
#define pii pair<int, int>
#define pLi pair<long long, int>
typedef priority_queue<pLi, vector<pLi>, greater<pLi>> minHeap;

const long long inf = 1e13;

class Graph
{
public:
	int vertex;
	vector<vector<pii>> adj;
public:
	Graph(int vertex);
	void addEdge(int u, int v, int w);
	void dijkstra(int source, int target);
};

Graph :: Graph(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
}

void Graph :: addEdge(int u, int v, int w)
{
	adj[u].push_back(mp(v, w));
	adj[v].push_back(mp(u, w));
}

void Graph :: dijkstra(int source, int target)
{
	minHeap heap;

	/* Handle overflows */
	vector<long long> dist(vertex, inf);
	vector<int> parent(vertex, -1);
	
	dist[source] = 0;
	heap.push(mp(dist[source], source));

	while(not heap.empty())
	{
		auto curr_dist = heap.top().first;
		auto source = heap.top().second;
		heap.pop();

		/* This step is important. Heap can contain duplicates */
		/* Notice the inequality */
		if(curr_dist > dist[source])
			continue;

		for(auto c_pair : adj[source])
		{
			auto child = c_pair.first;
			auto weight = c_pair.second;

			if(dist[child] > dist[source] + weight)
			{
				dist[child] = dist[source] + weight;
				parent[child] = source;
				heap.push(mp(dist[child], child));
			}
		}
	}
	/* Standard Dijkstra's algorithm ends here */


	if(parent[target] == -1)
	{
		cout << -1 << endl;
		return;
	}

	vector<int> res;

	res.push_back(target);
	while(parent[target] != -1)
	{
		target = parent[target];
		res.push_back(target);
	}

	reverse(res.begin(), res.end());

	for(auto ele : res)
		cout << ele + 1 << " ";

	cout << endl;
}

void solve()
{
	int vertex, edges;
	cin >> vertex >> edges;

	Graph graph(vertex);

	map<pii, int> edge_map;

	for(int i = 0; i < edges; i++)
	{
		int l, r, w;
		cin >> l >> r >> w;

		l--; r--;
		graph.addEdge(l, r, w);
	}

	graph.dijkstra(0, vertex - 1);
}

int main()
{
	solve();
	return 0;
}

