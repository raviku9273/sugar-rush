#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 10;
const int n_high = 15;
const int edge_max = 3*(int)1e5;
const int fac = 2;
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

#define endl '\n'

void generate()
{
	int n = rnd.next(n_low, n_high);

	int t_edges = rnd.next(1, fac*n);
	
	if(t_edges > edge_max)
		t_edges = edge_max;

	set<pair<int, int>> edge_set;

	while(edge_set.size() != t_edges)
	{
		edge_set.insert(gen_edge(n));
	}

	cout << n << " " << t_edges << endl;
	for(auto ele : edge_set)
	{
		cout << ele.first << " " << ele.second;
		cout << endl;
	}
}
int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	generate();
	return 0;
}
