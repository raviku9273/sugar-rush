#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = 1000;
	int k = rand(500, n);

	cout << n << endl;
	cout << k << endl;
}
