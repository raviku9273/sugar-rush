#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int layer_low = 1;
const int layer_high = 10;
const int mod_low = 3;
const int mod_high = 10;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen()
{
	cout << rnd.next(layer_low, layer_high) << endl;
	cout << rnd.next(mod_low, mod_high) << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen();
	return 0;
}

