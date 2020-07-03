#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

#define pii pair<int, int>
#define mp make_pair
typedef priority_queue<pii, vector<pii>, greater<pii>> minHeap;

int k;

inline int bind(int x, int avail)
{
	return x*k + avail;
}

class Graph
{
public:
	int vertex;
	vector<vector<pii>> adj;
public:
	Graph(int vertex);
	void addEdge(int u, int v, int w);
	vector<int> dijkstra(int source);
};

Graph :: Graph(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
}

/* Note : We are only adding directed edges. Think Why? */
void Graph :: addEdge(int u, int v, int w)
{
	adj[u].push_back(mp(v, w));
}

vector<int> Graph :: dijkstra(int source)
{
	minHeap heap;

	vector<int> dist(vertex, inf);
	
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
				heap.push(mp(dist[child], child));
			}
		}
	}

	return dist;
}

void solve()
{
	int vertex, edges;
	cin >> vertex >> edges >> k;

	k = min(k, edges);
	k++;
	
	/* Now, all vertices can avail a benefit of 0...(k-1) */
	
	/* Build the state graph of n*k vertices */
	Graph graph(vertex*k);

	for(int i = 0; i < edges; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		u--; v--;

		for(int avail = 0; avail < k; avail++)
		{
			/* Very important : You have an option of saving your move */
			graph.addEdge(bind(u, avail), bind(v, avail), w);
			graph.addEdge(bind(v, avail), bind(u, avail), w);

			if(avail == 0)
				continue;

			graph.addEdge(bind(u, avail), bind(v, avail - 1), 0);
			graph.addEdge(bind(v, avail), bind(u, avail - 1), 0);
		}
	}

	/* Take care of the starting point of Dijkstra */
	auto dist = graph.dijkstra(bind(0, k - 1));

	vector<int> res(vertex, inf);

	for(int i = 0; i < dist.size(); i++)
		res[i/k] = min(res[i/k], dist[i]);

	for(auto ele : res)
		cout << ele << " ";

	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}
