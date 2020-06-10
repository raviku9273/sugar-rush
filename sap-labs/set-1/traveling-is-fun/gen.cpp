#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = rand(2, 2*(int)(1e5));
	int g = rand(0, n);

	long long worst = 1LL*n*(n - 1)/2;
	worst = min(worst, (long long)(1e5));

	int q = rand(1, (int)(worst));
	
	vector<int> origin(q), dest(q);
	for(int i = 0; i < q; i++)
	{
		origin[i] = rand(1, n);

		dest[i] = rand(1, n);
		while(origin[i] == dest[i])
			dest[i] = rand(1, n);

	}

	cout << n << endl;
	cout << g << endl;

	cout << q << endl;
	for(auto ele : origin)
		cout << ele << endl;

	cout << q << endl;
	for(auto ele : dest)
		cout << ele << endl;

	return 0;
}
