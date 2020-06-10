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
	
	int n = rand(1, 1000);

	set<int> a;

	while((int)a.size() != n)
		a.insert(rand(1, 1000));
	
	int val = rand(1, 1000);

	cout << n << endl;
	for(auto ele : a)
		cout << ele << endl;

	cout << val << endl;
	
	return 0;
}
