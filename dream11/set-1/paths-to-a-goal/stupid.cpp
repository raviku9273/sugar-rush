#include <bits/stdc++.h>
using namespace std;

set<string> collection;
int lim, start, finish;

bool valid(string &str)
{
	int curr = start;

	for(auto ele : str)
	{
		if(ele == 'l')
			curr -= 1;
		else
			curr += 1;

		if(curr < 0 or curr > lim)
			return false;
	}

	return (curr == finish);
}

string gen_string(string &str, int mask)
{
	string res = "";

	for(int i = 0; i < str.length(); i++)
	{
		if( ( 1 << i) & mask)
			res += str[i];
	}

	return res;
}

void solve(string &str)
{
	int n = str.length();

	int biggest_mask = ( 1 << n) - 1;

	for(int i = 0; i <= biggest_mask; i++)
	{
		string curr = gen_string(str, i);

		if(valid(curr))
			collection.insert(curr);
	}
}

int main()
{
	string str;
	cin >> str;

	cin >> lim;
	cin >> start >> finish;

	solve(str);
	cout << collection.size() << endl;

	return 0;
}
