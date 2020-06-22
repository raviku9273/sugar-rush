#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int vertex_low = 100;
const int vertex_high = 100;
/********************* Custom Inputs ***************************/

#define endl '\n'

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	int vertex = rnd.next(vertex_low, vertex_high);
	
	int edges = min(200, vertex*(vertex - 1)/2);

	set<pair<pair<int, int>, int>> edge_set;

	int n = vertex;
	while(edge_set.size() != edges)
	{
		int u = rnd.next(1, n);
		int v = rnd.next(1, n);

		while(u == v)
			v = rnd.next(1, n);

		int w = rnd.next(1, 100);
		edge_set.insert(make_pair(make_pair(u,v), w));
	}

	vector<int> from, to, weight;
	for(auto ele : edge_set)
	{
		from.push_back(ele.first.first);
		to.push_back(ele.first.second);
		weight.push_back(ele.second);
	}

	cout << vertex << endl;

	cout << edges << endl;
	for(auto &ele : from)
		cout << ele << endl;

	cout << edges << endl;
	for(auto &ele : to)
		cout << ele << endl;

	cout << edges << endl;
	for(auto &ele : weight)
		cout << ele << endl;

	return 0;
}
