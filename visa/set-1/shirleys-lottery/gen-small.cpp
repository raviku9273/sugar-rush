#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1;
const int n_high = 15;
const long long val_low = 1;
const long long val_high = 10;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_array(int n)
{
	vector<long long> a(n);

	for(auto &ele : a)
		ele = rnd.next(val_low, val_high);

	cout << n << endl;
	for(auto &ele : a)
		cout << ele << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);


	int n = rnd.next(n_low, n_high);

	gen_array(n);
	gen_array(n);
	return 0;
}

