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
		long long n;
		n = 1LL*rand(1, (int)(1e7))*rand(1, (int)(1e7));
		cout << n << endl;
	}

	return 0;
}
