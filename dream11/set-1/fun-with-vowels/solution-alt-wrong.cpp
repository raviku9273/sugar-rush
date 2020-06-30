#include <bits/stdc++.h>
using namespace std;

int fun_with_vowels(string str)
{
	int A = 0, E = 0, I = 0, O = 0, U = 0;

	int ind = str.find('a');

	if(ind == string :: npos)
		return 0;

	for(int i = ind; i < str.length(); i++)
	{
		if(str[i] == 'a')
			A++;
		
		if(str[i] == 'e')
			E = max(A, E) + 1;

		if(str[i] == 'i')
			I = max(E, I) + 1;

		if(str[i] == 'o')
			O = max(I, O) + 1;

		if(str[i] == 'u')
			U = max(O, U) + 1;
	}

	return U;
}

int main()
{
	string str;
	cin >> str;

	cout << fun_with_vowels(str) << endl;
	return 0;
}

