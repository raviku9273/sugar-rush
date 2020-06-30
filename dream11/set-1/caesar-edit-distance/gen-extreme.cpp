#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 500;
const int n_high = 500;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_string()
{
	int n = rnd.next(n_low, n_high);

	string str = "";

	for(int i = 0; i < n; i++)
		str += 'a' + rnd.next(0, 25);

	cout << str << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_string();
	gen_string();
	return 0;
}

