#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

void generateEdge(int &x, int &y, int vertex)
{
	x = rand(1, vertex);
	y = rand(1, vertex);

	while( x == y)
	{
		x = rand(1, vertex);
		y = rand(1, vertex);
	}
}
void GenerateGraph()
{
	int vertex = rand(5, 1000);

	int disconnected = rand(0, 1);
	
	int edges;
	if(disconnected)
		edges = rand(1, vertex - 2);
	else
		edges = rand(1, vertex*(vertex - 1)/2);
	
	set<pair<int, int>> container;

	cout << vertex << " " << edges << endl;

	for(int i = 0; i < edges; i++)
	{
		int x, y;
		generateEdge(x,y, vertex);

		auto p = make_pair(x, y);
		auto rev_p = make_pair(y, x);

		while(container.find(p) != container.end() or container.find(rev_p) != container.end())
		{
			generateEdge(x, y, vertex);
			p = make_pair(x, y);
			rev_p = make_pair(y, x);
		}
		
		container.insert(p);
	}

	for(auto ele : container)
		cout << ele.first << " " << ele.second << endl;

	return;
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	GenerateGraph();
	return 0;
}
