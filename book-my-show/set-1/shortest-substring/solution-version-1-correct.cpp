#include <bits/stdc++.h>
using namespace std;

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

	for(auto ele : target)
		target_freq[ele]++;

	int left = 0, right = 0, matched = 0, res = INT_MAX;
	int start = -1;

	/* Equality of lHs right? */
	while(left <= right and right < n)
	{
		auto ele = source[right];
		source_freq[ele]++;

		if(not target_freq.count(ele))
		{
			right++;
			continue;
		}

		/* Don't use default values blindly : You may end up inserting elements */
		if(source_freq[ele] == target_freq[ele])
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
