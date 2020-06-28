#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1;
const int n_high = 3000;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_string()
{
	int n = rnd.next(n_low, n_high);

	for(int i = 0; i < n; i++)
		cout << (char)('a' + rnd.next(0, 25));

	cout << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_string();
	return 0;
}

