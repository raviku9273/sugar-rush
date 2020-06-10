#include<bits/stdc++.h>
using namespace std;

void brute(string str)
{
	int n = str.length();
	
	long long count = 0;
	for(int i = 0; i < n; i++)
	{
		map<char, int> myMap;
		for(int j = i; j < n; j++)
		{
			myMap[str[j]]++;
			
			int odd = 0;
			for(auto ele : myMap)
				if(ele.second %2 != 0)
					odd++;

			if(odd == 0 or odd == 1)
				count += 1;
		}
	}

	cout << count << endl;
}


int main()
{
	string str;
	cin >> str;

	brute(str);
	return 0;
}
