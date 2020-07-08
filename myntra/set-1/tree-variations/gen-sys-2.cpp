#include <iostream>
#include <assert.h>

#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1e5;
const int n_high = 1e5;
const int max_val = 100;
/********************* Custom Inputs ***************************/

#define endl '\n'

void smart_gen()
{
	int n = rnd.next(n_low, n_high);
	vector<int> color(n, 1);
	
	vector<int> colored;

	set<int> un_colored;
	for(int i = 0; i < n; i++)
		un_colored.insert(i);

	int source = rnd.next(0, n - 1);
	color[source] = max_val;

	un_colored.erase(source);
	colored.push_back(source);

	int nodes_left = un_colored.size();

	int cnt = 0;
	int total_edges = n - 1;

	cout << n << " " << n - 1 << endl;
	for(int val = max_val; val > 1; val-= rnd.next(1, 2))
	{

		if(cnt == total_edges)
			break;

		int alpha = rnd.next(0, 2*nodes_left/val);
		for(int i = 0; i < alpha; i++)
		{
			int u = colored[rnd.next(0, (int)colored.size() - 1)];
			int v = *un_colored.begin();
			un_colored.erase(v);

			color[v] = val;
			colored.push_back(v);

			cout << u << " " << v << endl;
			cnt++;

			if(cnt == total_edges)
				break;
		}
	}

	if(cnt < total_edges)
	{
		while(not un_colored.empty())
		{
			int u = colored[rnd.next(0, (int)colored.size() - 1)];
			int v = *un_colored.begin();
			un_colored.erase(v);

			color[v] = 1;
			colored.push_back(v);

			cout << u << " " << v << endl;
			cnt++;

		}
	}

	assert(cnt == total_edges);


	cout << n << endl;
	for(auto &ele : color)
	{
		if(ele == max_val)
			if(rnd.next(0, 1))
				ele = 1;

		cout << ele << endl;
	}
}

void gen_tree(int n_low, int n_high)
{
	int n = rnd.next(n_low, n_high);

	cout << n << " " << (n - 1) << endl;

	vector<pair<int, int>> edges;
	for(int i = 2; i <= n; i++)
		edges.emplace_back(rnd.next(1, i - 1), i);
	
	/* Rename vertices */
	vector<int> perm(n + 1);
	for(int i = 1; i <= n; i++)
		perm[i] = i;

	shuffle(perm.begin() + 1, perm.end());

	shuffle(edges.begin(), edges.end());

	for(auto edge : edges)
	{
		int a = edge.first, b = edge.second;

		if(rnd.next(0, 1))
			swap(a, b);

		cout << perm[a] << " " << perm[b] << endl;
	}
}
int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	smart_gen();

	return 0;
}
