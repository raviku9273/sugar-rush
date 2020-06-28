#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 100;
const int n_high = 100;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_string()
{
	int n = rnd.next(n_low, n_high);

	string str = "";
	for(int i = 0; i < n; i++)
		str += (char)('a' + rnd.next(0, 25));

	string rev = str;
	reverse(rev.begin(), rev.end());

	string res = str;
	res += 'c';
	res += rev;

	cout << res << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_string();
	return 0;
}

