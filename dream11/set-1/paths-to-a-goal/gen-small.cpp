#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1;
const int n_high = 5;
const int lim_low = 0;
const int lim_high = 5;
/********************* Custom Inputs ***************************/

#define endl '\n'

void generate()
{
	int n = rnd.next(n_low, n_high);

	string str = "";

	for(int i = 0; i < n; i++)
		str += (rnd.next(0,1) ? 'l' : 'r');

	int lim = rnd.next(lim_low, lim_high);

	cout << str << endl;
	cout << lim << endl;

	cout << rnd.next(0, lim) << endl;
	cout << rnd.next(0, lim) << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	generate();
	return 0;
}

