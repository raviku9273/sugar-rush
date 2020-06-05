#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	/* Start from 5 */
	int tc_num = 5;

	for(int i = 0; i < 2; i++)
		cout << "gen-all-ones " << rand() << " > " << tc_num++ << endl;

	for(int i = 0; i < 2; i++)
		cout << "gen-all-zeroes " << rand() << " > " << tc_num++ << endl;

	for(int i = 0; i < 5; i++)
		cout << "gen-diagonal-minus " << rand() << " > " << tc_num++ << endl;

	for(int i = 0; i < 10; i++)
		cout << "gen-small " << rand() << " > " << tc_num++ << endl;

	for(int i = 0; i < 100; i++)
		cout << "gen-no-thorns " << rand() << " > " << tc_num++ << endl;

	for(int i = 0; i < 100; i++)
		cout << "gen " << rand() << " > " << tc_num++ << endl;

	for(int i = 0; i < 10; i++)
		cout << "gen-extreme " << rand() << " > " << tc_num++ << endl;

	for(int i = 0; i < 10; i++)
		cout << "gen-extreme-no-thorns " << rand() << " > " << tc_num++ << endl;


	return 0;
}
