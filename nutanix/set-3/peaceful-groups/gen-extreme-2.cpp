#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = 1e5;
	cout << n << endl;

	for(int i = 0; i < n; i++)
		cout << 1 << " ";

	cout << endl;
	return 0;

}
