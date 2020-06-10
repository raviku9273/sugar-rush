#include<bits/stdc++.h>
using namespace std;

void angryAnimals(int n, vector<int> &a, vector<int> &b)
{
	for(auto &ele : a)
		ele--;

	for(auto &ele : b)
		ele--;
	
	vector<vector<bool>> conflict(n, vector<bool>(n, false));
	
	for(int i = 0; i < a.size(); i++)
	{
		conflict[a[i]][b[i]] = true;
		conflict[b[i]][a[i]] = true;
	}

	long long res = 0;
	for(int i = 0; i < n; i++)
	{
		int count = 1;

		for(int j = i + 1; j < n; j++)
		{
			int incoming = j;

			bool has_conflict = false;
			for(int k = i; k < j; k++)
				if( conflict[k][incoming] )
					has_conflict = true;

			if(not has_conflict)
			{
				count += 1;
			}

			else
			{
				break;
			}
		}

		res += count;
	}

	cout << res << endl;
}

int main()
{
	int n;
	cin >> n;

	int sz;
	cin >> sz;
	vector<int> a(sz), b(sz);

	for(auto &ele : a)
		cin >> ele;

	int fake;
	cin >> fake;

	for(auto &ele : b)
		cin >> ele;
	
	angryAnimals(n, a, b);
	return 0;
}
