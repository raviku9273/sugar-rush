#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int speed_low = 4;
const int speed_high = 50;
const int n_low = 5;
const int n_high = 1000;
const int val_low = 3;
const int val_high = INT_MAX;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen()
{
	cout << rnd.next(speed_low, speed_high) << endl;

	int n = rnd.next(n_low, n_high);

	cout << n << endl;

	for(int i = 0; i < n; i++)
	{
		cout << rnd.next(val_low, val_high) << " ";
		cout << rnd.next(val_low, val_high) << endl;
	}

}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen();
	return 0;
}

