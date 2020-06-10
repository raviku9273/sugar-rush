#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = 5*(int)(1e4);

	vector<int> start(n), finish(n), profit(n);

	for(int i = 0; i < n; i++)
	{
		start[i] = rand(1, (int)(1e9) - 5);
		finish[i] = rand(start[i] + 1, (int)(1e9));
		profit[i] = rand(1, (int)(1e4));
	}

	cout << n << endl;
	for(int i = 0; i < n; i++)
		cout << start[i] << endl;

	cout << n  << endl;
	for(int i = 0; i < n; i++)
		cout << finish[i] - start[i] << endl;

	cout << n << endl;
	for(int i = 0; i < n; i++)
		cout << profit[i] << endl;

	return 0;
}
