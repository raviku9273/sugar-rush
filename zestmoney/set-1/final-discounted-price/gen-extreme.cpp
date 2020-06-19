#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1e5;
const int n_high = 1e5;
const long long val_low = 1;
const long long val_high = 1e6;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_array(int n_low, int n_high, long long val_low, long long val_high)
{
	int n = rnd.next(n_low, n_high);

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

	gen_array(n_low, n_high, val_low, val_high);
	return 0;
}

