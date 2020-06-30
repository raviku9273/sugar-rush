#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/

const int n_low = 5*(int)(1e5) - 1;
const int n_high = 5*(int)(1e5) - 1;

/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_array()
{
	vector<char> list = {'a', 'e', 'i', 'o', 'u'};

	int n = rnd.next(n_low, n_high);
	
	for(int i = 0; i < n; i++)
		cout << list[rnd.next(0, 4)];

	cout << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_array();
	return 0;
}

