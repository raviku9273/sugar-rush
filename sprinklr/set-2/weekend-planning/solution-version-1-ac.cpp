#include<bits/stdc++.h>
using namespace std;

/* Assumption : The graph is connected */

const int inf = 1e8 + 8;
#define pii pair<int, int>
#define mp make_pair

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
	vector<int> dist(vertex, inf);

	priority_queue<pii, vector<pii>, greater<pii>> heap;

	/* Elements are (dist, vertex) */
	
	/* The only part different from normal dijkstra */
	for(int avail = 0; avail < k; avail++)
	{
		dist[bind(source, avail)] = 0;
		heap.push(mp(0, bind(source, avail)));
	}

	while(not heap.empty())
	{
		auto ele = heap.top();
		heap.pop();

		int curr_dist = ele.first;
		int curr_node = ele.second;

		/* There can be useless values in the heap */
		if(curr_dist > dist[curr_node])
			continue;

		for(auto child : adj[curr_node])
		{
			int child_node = child.first;
			int child_weight = child.second;

			if(dist[child_node] > dist[curr_node] + child_weight)
			{
				dist[child_node] = dist[curr_node] + child_weight;
				heap.push(mp(dist[child_node], child_node));
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

			/* Be careful while adding edges. Very tricky part */
			graph.addEdge(bind(u, avail), bind(v, avail - 1), 0);
			graph.addEdge(bind(v, avail), bind(u, avail - 1), 0);
		}
	}

	/* Take care of the starting point of Dijkstra */
	auto dist = graph.dijkstra(0);

	vector<int> res(vertex, inf);

	for(int i = 0; i < vertex; i++)
		for(int avail = 0; avail < k; avail++)
			res[i] = min(res[i], dist[bind(i, avail)]);

	for(auto ele : res)
		cout << ele << " ";

	cout << endl;
}

int main()
{
	solve();
	return 0;
}
