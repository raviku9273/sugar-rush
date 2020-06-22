#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1;
const int n_high = 5;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_array(int n_low, int n_high)
{
	int n = rnd.next(n_low, n_high);

	vector<long long> a(n);

	for(auto &ele : a)
		ele = rnd.next(0, min(n, 100));

	cout << n << endl;
	for(auto &ele : a)
		cout << ele << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_array(n_low, n_high);
	return 0;
}

