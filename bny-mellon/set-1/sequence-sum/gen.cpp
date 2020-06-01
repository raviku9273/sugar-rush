#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));

	int low = -1e8;
	int high = 1e8;

	int j = rand(low, high);
	int i = rand(low, j);
	int k = rand(low, j);

	cout << i << " ";
	cout << j << " ";
	cout << k << " ";
	cout << endl;

	return 0;
}
