#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

char rand_char()
{
	char res = 'a' + rand(0, 25);
	return res;
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = 1e3;
	cout << n << endl;

	int word_len = 3000;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < word_len; j++)
		{
			cout << rand_char();
		}
		cout << endl;
	}

	int tar_len = rand(1, word_len);

	for(int i = 0; i < tar_len; i++)
		cout << rand_char();

	cout << endl;

	return 0;
}
