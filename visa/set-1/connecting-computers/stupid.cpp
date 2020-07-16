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

void test()
{
	int vertex;
	cin >> vertex;
	
	UnionFind dsu(vertex);

	int edges;
	cin >> edges;

	for(int i = 0; i < edges; i++)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;
		
		dsu.union_sets(u, v);
	}
	
	int comp = 0;

	for(int i = 0; i < vertex; i++)
		if(dsu.parent[i] == i)
			comp++;

	if(edges >= vertex - 1)	
		cout << comp - 1 << endl;
	else
		cout << -1 << endl;
}

int main()
{
	test();
	return 0;
}
