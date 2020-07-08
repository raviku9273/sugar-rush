#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1;
const int n_high = 100;
const int k_low = 1;
const int k_high = 20;
const long long arrival_low = 1;
const long long arrival_high = 1e9;
const long long load_low = 1;
const long long load_high = 1e9;
/********************* Custom Inputs ***************************/

int n_taken;
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

void gen_unique_array(int n_low, int n_high, long long val_low, long long val_high)
{
	int n = rnd.next(n_low, n_high);
	n_taken = n;

	set<long long> a;

	while((int)a.size() != n)
		a.insert(rnd.next(val_low, val_high));

	cout << n << endl;
	for(auto &ele : a)
		cout << ele << endl;
}
int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	cout << rnd.next(k_low, k_high) << endl;

	gen_unique_array(n_low, n_high, arrival_low, arrival_high);
	gen_array(n_taken, n_taken, load_low, load_high);

	return 0;
}

