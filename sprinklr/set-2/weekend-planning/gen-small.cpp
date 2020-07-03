#include <iostream>
#include "testlib.h"

#define mp make_pair

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 6;
const int n_high = 20;
const int c = 3;
const int edge_max = 40;
const long long w_low = 1;
const long long w_high = 1000;
const int k_low = 0;
const int k_high = 3;
/********************* Custom Inputs ***************************/

#define endl '\n'

pair<int, int> gen_edge(int n)
{
	int x = rnd.next(1, n);
	int y = rnd.next(1, n);

	while(x == y)
	{
		x = rnd.next(1, n);
		y = rnd.next(1, n);
	}

	return mp(min(x, y), max(x, y));
}

void gen_connected_graph()
{
	int n = rnd.next(n_low, n_high);

	vector<pair<int, int>> edges;
	for(int i = 2; i <= n; i++)
		edges.emplace_back(rnd.next(1, i - 1), i);
	
	/* Rename vertices */
	vector<int> perm(n + 1);
	for(int i = 1; i <= n; i++)
		perm[i] = i;

	shuffle(perm.begin() + 1, perm.end());

	shuffle(edges.begin(), edges.end());

	set<pair<int, int>> g_edges;
	for(auto edge : edges)
	{
		int a = edge.first, b = edge.second;

		if(rnd.next(0, 1))
			swap(a, b);

		int x = perm[a];
		int y = perm[b];

		if(x > y)
			swap(x, y);

		g_edges.insert(mp(x, y));
	}

	int total_edges = n - 1;
	total_edges += rnd.next(0, (c*n)/rnd.next(2, 10));

	if(total_edges > edge_max)
		total_edges = edge_max;

	while(g_edges.size() != total_edges)
		g_edges.insert(gen_edge(n));

	cout << n << " " << total_edges << " ";
	cout << rnd.next(k_low, k_high) << endl;

	for(auto ele : g_edges)
	{
		cout << ele.first << " ";
		cout << ele.second << " ";
		cout << rnd.next(w_low, w_high) << endl;
	}
}
int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_connected_graph();
	return 0;
}
