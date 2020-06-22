#include <bits/stdc++.h>
using namespace std;

/* Invariants : 
 * 1) When the outer 'while' loop starts, the window should be incomplete
 * 2) When the inner 'while' loop ends, the window should be incomplete
 * Debugging Tip :
 * 1) Don't blindly access the element without checking for existence,
 * else, you might end up inserting into the map
 */

class Solution
{
public:
	string minWindow(string source, string target);
};

/* Minimum window in 'source' which contains anagaram of 'target' (with freq) */
string Solution :: minWindow(string source, string target)
{
	int n = source.length();

	map<char, int> source_freq, target_freq;

	for(auto &ele : target)
		target_freq[ele]++;

	int left = 0, right = 0, matched = 0, res = INT_MAX;
	int start = -1;

	while(left <= right and right < n)
	{
		auto ele = source[right];
		source_freq[ele]++;

		/* Don't use default values blindly : You may end up inserting elements */
		if(target_freq.count(ele) and source_freq[ele] == target_freq[ele])
			matched++;

		if(matched == (int)target_freq.size())
		{
			while(left <= right and right < n)
			{
				int curr_len = right - left + 1;

				if(res > curr_len)
				{
					res = curr_len;
					start = left;
				}
					
				ele = source[left];
				source_freq[ele]--;

				if(target_freq.count(ele) and source_freq[ele] < target_freq[ele])
				{
					matched--;
					left++;
					break;
				}

				
				left++;
			}
		}
		right++;
	}


	if(res == INT_MAX)
		return "";

	return source.substr(start, res);
}

int main()
{
	Solution sol;

	string source, target;
	cin >> source >> target;

	cout << sol.minWindow(source, target) << endl;
	return 0;
}
