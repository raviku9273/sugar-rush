/* I didn't take care of non-splittable strings in the first draft. See Post below.
 * Idea borrowed from 
 * https://leetcode.com/problems/special-binary-string/discuss/113213/12-liner-readable-clean-C%2B%2B-(with-explanation-and-comments)
 * Tricky Test Case : (()(())) - Non Splittable String
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

	if(n == 0)
		return str;

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

	for(auto &non_split : collection)
	{
		int len = non_split.length();
		non_split = '1' + makeLargestSpecial(non_split.substr(1, len - 2)) + '0';
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
