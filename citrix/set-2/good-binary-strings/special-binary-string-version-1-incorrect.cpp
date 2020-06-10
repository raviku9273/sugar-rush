/* Incorrect : 11011000
 * It cannot be written as special + special
 * However, it has 2 embedded special strings
 */

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string makeLargestSpecial(string str);
};

string Solution :: makeLargestSpecial(string str)
{
	int n = str.length();

	vector<string> collection;

	string entry = "";
	int count = 0;

	for(int i = 0; i < n; i++)
	{
		entry += str[i];

		if(str[i] == '1')
			count++;
		else
			count--;

		if(count == 0)
		{

			collection.push_back(entry);
			entry = "";
		}
	}

	sort(collection.begin(), collection.end(), greater<string>());

	string res = "";
	for(auto ele : collection)
		res += ele;

	return res;
}

int main()
{
	string str;
	cin >> str;

	Solution sol;
	cout << sol.makeLargestSpecial(str) << endl;

	return 0;
}
