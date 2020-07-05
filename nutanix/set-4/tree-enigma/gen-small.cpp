#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1;
const int n_high = 20;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_tree(int n_low, int n_high)
{
	int n = rnd.next(n_low, n_high);

	cout << n << endl;

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

	for(int i = 0; i < n; i++)
		cout << rnd.next(0, 1) << " ";
	cout << endl;

	for(int i = 0; i < n; i++)
		cout << rnd.next(0, 1) << " ";
	cout << endl;
}
int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_tree(n_low, n_high);
	return 0;
}
