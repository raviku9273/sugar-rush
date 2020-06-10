#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = 200;
	int k = rand(150, 200);

	cout << n << endl;
	cout << k << endl;
}
