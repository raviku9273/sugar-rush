#include <bits/stdc++.h>
using namespace std;

/* ### READ-ONLY PART ### */
int warShips(int input1, int input2)
/* ### READ-ONLY PART ### */
{
	int L = input1, M = input2;
	queue<pair<int, int>> q;

	pair<int, int> p;
	int cnt = 0, y, i;

	q.push({2, 0});

	while(! q.empty())
	{
		p = q.front(); q.pop();
		cnt = (cnt + 1)%M;

		if(p.second + 1 < L)
		{
			y = ((p.first*p.first) + 1)%M;
			for(i = 0; i < y; i++)
			{
				q.push({i, p.second + 1});
			}
		}
	}
	return cnt;
}

int main()
{
	int input1, input2;
	cin >> input1 >> input2;

	cout << warShips(input1, input2);
	cout << endl;
	return 0;
}

