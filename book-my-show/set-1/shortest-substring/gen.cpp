#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1;
const int n_high = 1e5;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_string(int n_low, int n_high)
{
	int n = rnd.next(n_low, n_high);
	
	string str = "";

	for(int i = 0; i < n; i++)
		str += (char)('a' + rnd.next(0, 25));

	cout << str << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_string(n_low, n_high);
	return 0;
}

