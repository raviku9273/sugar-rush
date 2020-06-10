#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = rand(1, 100);
	
	cout << n << endl;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << rand(1, 100) << " ";
		}
		
		cout << endl;
	}

	return 0;
}
