#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int t_low = 1e5;
const int t_high = 2*(int)(1e5);
const int n_low = 1;
const int n_high = 1e6;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_pattern()
{
	int t = rnd.next(t_low, t_high);
	cout << t << endl;

	for(int i = 0; i < t; i++)
		cout << rnd.next(n_low, n_high) << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_pattern();
	return 0;
}

