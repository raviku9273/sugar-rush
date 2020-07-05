#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int t_low = 10;
const int t_high = 10;
const int n_low = 1e5;
const int n_high = 1e5;
const int edge_max = 1e5;
const int c_low = 1e8;
const int c_high = 1e9;
const int r_low = 1e8;
const int r_high = 1e9;
/********************* Custom Inputs ***************************/

#define endl '\n'
#define mp make_pair

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

void gen_graph()
{
	int n = rnd.next(n_low, n_high);
	
	long long total_edges = rnd.next(1LL, 1LL*n*(n-1)/2);

	if(total_edges > edge_max)
		total_edges = edge_max;

	set<pair<int, int>> edges;

	while(edges.size() != total_edges)
		edges.insert(gen_edge(n));

	int r = rnd.next(r_low, r_high);
	int c = rnd.next(c_low, c_high);


	if(c < r)
		swap(c, r);

	cout << n << " " << total_edges << " ";
	cout << c << " " << r << endl;

	for(auto ele : edges)
	{
		cout << ele.first << " " << ele.second << endl;
	}
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	int t = rnd.next(t_low, t_high);

	cout << t << endl;

	for(int i = 0; i < t; i++)
		gen_graph();

	return 0;
}

