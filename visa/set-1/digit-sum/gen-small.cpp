#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const long long n_low = 1;
const long long n_high = 1e5;
/********************* Custom Inputs ***************************/

#define endl '\n'

void generate()
{
	auto low = rnd.next(n_low, n_high);
	auto high = rnd.next(n_low, n_high);

	if(low > high)
		swap(low, high);

	cout << low << endl;
	cout << high << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	generate();
	return 0;
}

