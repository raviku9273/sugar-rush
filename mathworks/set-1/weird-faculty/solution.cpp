#include<bits/stdc++.h>
using namespace std;

void weird_faculty(vector<int> &a)
{
	int n = a.size();

	for(auto &ele : a)
		if(ele == 0)
			ele = -1;

	vector<int> prefix = a;
	for(int i = 1; i < n; i++)
		prefix[i] += prefix[i - 1];

	int total = prefix.back();

	if(total < 0)
	{
		cout << 0 << endl;
		return;
	}

	int req = total/2;
	
	int res = -1;
	for(int i = 0; i < n; i++)
	{
		if(prefix[i] > req)
		{
			res = i;
			break;
		}
	}

	assert(res != -1);
	cout << res + 1 << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	weird_faculty(a);
	return 0;
}
