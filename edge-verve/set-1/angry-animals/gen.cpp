#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = rand(5, 1000);
	
	cout << n << endl;

	int m = rand(1, 1000);
	cout << m << endl;

	vector<int> a(m), b(m);

	for(int i = 0; i < m; i++)
	{
		a[i] = rand(1, n);
		
		int new_val = rand(1, n);
		while( new_val == a[i])
			new_val = rand(1, n);

		b[i] = new_val;
	}
	
	for(auto &ele : a)
		cout << ele << endl;
	
	cout << m << endl;

	for(auto &ele : b)
		cout << ele << endl;
	return 0;
}
