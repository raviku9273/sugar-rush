#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = 1000;

	string str = "";
	for(int i = 0; i < n; i++)
		str += 'a' + rand(0,25);

	cout << str << endl;	
	return 0;
}
