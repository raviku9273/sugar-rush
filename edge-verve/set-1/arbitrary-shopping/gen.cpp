#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = rand(1, 1000);
	cout << n << endl;
	
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int num = rand(1, 100);
		sum += num;

		cout << num << " ";
	}

	cout << rand(0, sum) << endl;

	return 0;
}
