#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1e4;
const int n_high = 5*(int)(1e6);
const long long val_low = 1;
const long long val_high = 1e9;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_array(int n_low, int n_high, long long val_low, long long val_high)
{
	int n = rnd.next(n_low, n_high);

	vector<long long> a(n);

	for(auto &ele : a)
		ele = rnd.next(val_low, val_high);

	int x = rnd.next(0, n - 1);
	int y = rnd.next(0, n - 1);

	int left = min(x, y);
	int right = max(x, y);

	sort(a.begin(), a.begin() + left);
	sort(a.begin() + right, a.end());

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

