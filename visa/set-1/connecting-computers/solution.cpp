#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
	vector<int> parent;
public:
	UnionFind(int n);
	int find_set(int v);
	void union_sets(int a, int b);
};

UnionFind :: UnionFind(int n)
{
	parent.resize(n);
	for(int i = 0; i < n; i++)
		parent[i] = i;
}

int UnionFind :: find_set(int v)
{
	if(v == parent[v])
		return v;

	int root_v = find_set(parent[v]);
	parent[v] = root_v;

	return root_v;
}

void UnionFind :: union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	
	if(a != b)
		parent[a] = b;
}

int minOperations(int comp_nodes, vector<int> comp_from, vector<int> comp_to)
{
	int vertex = comp_nodes;
	int edges = comp_from.size();

	UnionFind dsu(vertex);

	for(int i = 0; i < edges; i++)
	{
		int u = comp_from[i];
		int v = comp_to[i];
		u--; v--;
		
		dsu.union_sets(u, v);
	}
	
	int total_cc = 0;

	for(int i = 0; i < vertex; i++)
		if(dsu.parent[i] == i)
			total_cc++;

	if(edges >= vertex - 1)	
		return total_cc - 1;
	else
		return -1;
}

int main()
{
	int comp_nodes;
	cin >> comp_nodes;

	int edges;
	cin >> edges;

	vector<int> comp_from(edges), comp_to(edges);

	for(int i = 0; i < edges; i++)
		cin >> comp_from[i] >> comp_to[i];

	int res = minOperations(comp_nodes, comp_from, comp_to);
	cerr << res << endl;
	cout << res << endl;

	return 0;
}
