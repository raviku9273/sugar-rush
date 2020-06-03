#include<bits/stdc++.h>
using namespace std;

int n = 1e5;

int rev_num(int num)
{
	int rev = 0;
	while(num)
	{
		rev = rev*10 + (num %10);
		num /= 10;
	}

	return rev;
}

void solve()
{
	queue<int> bfs;

	bfs.push(1);
	
	vector<int> level(n + 1, -1);
	level[1] = 1;
	vector<int> parent(n + 1, -1);

	while(not bfs.empty())
	{
		int num = bfs.front();
		bfs.pop();
		
		if(num > 1e7)
			break;

		if(level[num + 1] == -1)
		{
			bfs.push(num + 1);
			level[num + 1] = level[num] + 1;
			parent[num + 1] = num;

		}

		if(level[rev_num(num)] == -1)
		{
			bfs.push(rev_num(num));
			level[rev_num(num)] = level[num] + 1;
			parent[rev_num(num)] =  num;
		}
	}

	for(int i = 1; i <= 10000 + 2; i++)
	{
		if((i%10 == 1) and i > 10 and ((i/10)%10 == 0))
			cout << endl;

		cout << i << " --> " <<  level[i] << endl;
		
		/* Uncomment to get the optimal steps */	
		/*
		cout << endl;
		cout << "Res for " << i << "--> " << level[i] << endl;
		int j = i

		while(j != -1)
		{
			cout << j << " --> ";
			j = parent[j];
		}

		cout << endl;
		*/
	}

}

int main()
{
	solve();
	return 0;
}
