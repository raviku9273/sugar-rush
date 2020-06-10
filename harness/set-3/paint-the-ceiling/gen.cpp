#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));

	// n, start, k, b, mod, maxArea	
	int n = rand(1, 2*(int)(1e7)) ;
	int start = rand(500, (int)(1e3)) ;
	int k = rand(500, (int)(1e3)) ;
	int b = rand(500, (int)(1e3)) ;
	int mod = rand(500, (int)(1e3)) ;
	
	long long first_area = rand(1, (int)(1e9));
	long long second_area = rand(1, (int)(1e9));
	
	cout << n << endl;
	cout << start << endl;
	cout << k << endl;
	cout << b << endl;
	cout << mod << endl;
	cout << first_area*second_area << endl;
	return 0;
}
