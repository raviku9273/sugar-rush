#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int vertex = 100;
	
	int edges = 200;

	cout << vertex << " " << edges << endl;

	set<pair<pair<int, int>, int>> edge_set;

	int n = vertex;
	while(edge_set.size() != edges)
	{
		int u = rand(1, n);
		int v = rand(1, n);

		while(u == v)
			v = rand(1, n);

		int w = rand(1, 100);
		edge_set.insert(make_pair(make_pair(u,v), w));
	}

	for(auto ele : edge_set)
	{
		cout << ele.first.first << " ";
		cout << ele.first.second << " ";
		cout << ele.second << endl;
	}

	return 0;
}
