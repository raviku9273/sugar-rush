#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int a, int b)
{
	return (0LL + a + b)%mod;
}

inline int mult(int a, int b)
{
	return (1LL*a*b)%mod;
}

class Tree
{
public:
	int vertex;
	vector<vector<int>> adj;
	vector<int> dp_incl, dp_excl, dp;

public:
	Tree(int vertex);
	void addEdge(int u, int v);
	void computeWays(int source, int parent);
};

Tree :: Tree(int vertex)
{
	this->vertex = vertex;
	adj.resize(vertex);
	dp_incl.resize(vertex), dp_excl.resize(vertex);
	dp.resize(vertex);
}

void Tree :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Tree :: computeWays(int source, int parent)
{
	dp_incl[source] = 1;
	dp_excl[source] = 1;

	for(int child : adj[source])
	{
		if(child != parent)
		{
			computeWays(child, source);
			dp_incl[source] = mult(dp_incl[source], dp_excl[child]);
			dp_excl[source] = mult(dp_excl[source],  dp[child]);
		}
	}

	dp[source] = add(dp_incl[source], dp_excl[source]);
}

void IndependentSet()
{
	int n;
	cin >> n;

	int edges = n - 1;

	Tree tree(n);

	for(int i = 0; i < edges; i++)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;

		tree.addEdge(u, v);
	}

	tree.computeWays(0, -1);
	cout << tree.dp[0] << endl;
}

int main()
{
	IndependentSet();
	return 0;
}

