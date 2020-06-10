#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));

	int n = 1e6;

	int k = n/2;

	vector<int> a(n);
	for(auto &ele : a)
		ele = rand(1, (int)(1e9));

	cout << k << endl;
	cout << n << endl;

	for(auto ele : a)
		cout << ele << endl;

	return 0;
}
