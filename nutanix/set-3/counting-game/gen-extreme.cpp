#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	int t = 1e5;
	cout << t << endl;

	for(int i = 0; i < t; i++)
	{
		cout << (i + 1) << endl;
	}

	return 0;
}
