#include <bits/stdc++.h>
using namespace std;

map<char, set<int>> pos;
string str;

int query(int left, int right)
{
	int res = 0;
	for(char letter = 'a'; letter <= 'z'; letter++)
	{
		auto &my_set = pos[letter];

		/* Don't use the lower_bound in algorithms library */
		auto itr = my_set.lower_bound(left);

		/* Don't do arithmetic : It's not random access, hence, O(n) */
		if(itr == my_set.end())
			continue;

		res += (*itr <= right);
	}

	return res;
}

void update(int ind, char new_letter)
{
	auto old_letter = str[ind];
	str[ind] = new_letter;

	pos[old_letter].erase(ind);
	pos[new_letter].insert(ind);
}

void solve()
{
	cin >> str;

	for(int i = 0; i < str.length(); i++)
		pos[str[i]].insert(i);

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int ind; char new_letter;
			cin >> ind >> new_letter;
			ind--;

			update(ind, new_letter);
		}
		else
		{
			int left, right;
			cin >> left >> right;
			left--; right--;

			cout << query(left, right) << endl;
		}
	}
}

int main()
{
	solve();
	return 0;
}
