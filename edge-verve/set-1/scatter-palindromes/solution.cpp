#include<bits/stdc++.h>
using namespace std;

void Scatter_Palindromes(string str)
{
	int n = str.length();
	long count = 0;
	for(int i = 0; i < n; i++)
	{
		int mask = 0;
		for(int j = i; j < n; j++)
		{
			mask = mask xor (1 << (str[j] - 'a'));
			
			if( __builtin_popcount(mask) <= 1)
				count += 1;
		}
	}

	cout << count << endl;
}

int main()
{
	string str;
	cin >> str;

	Scatter_Palindromes(str);
	return 0;
}

