#include <bits/stdc++.h>
using namespace std;

/* ### READ-ONLY PART ### */
int warShips(int input1, int input2)
/* ### READ-ONLY PART ### */
{
	int max_layers = input1;
	int mod = input2;

	queue<int> bfs;
	
	bfs.push(2);
	int layer = 1, res = 0;

	while(not bfs.empty())
	{
		if(layer > max_layers)
			break;

		int curr_size = bfs.size();
		while(curr_size--)
		{
			auto v = bfs.front();
			bfs.pop();

			res = (res + 1) % mod;

			int upper_limit = (v*v + 1) % mod;
			for(int nxt = 0; nxt < upper_limit; nxt++)
				bfs.push(nxt);
		}
		layer++;
	}

	return res;
}

int main()
{
	int input1, input2;
	cin >> input1 >> input2;

	cout << warShips(input1, input2);
	cout << endl;
	return 0;
}
