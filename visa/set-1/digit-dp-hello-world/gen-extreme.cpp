#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int t_low = 100;
const int t_high = 100;
const long long num_low = 1e15;
const long long num_high = 1e18;
/********************* Custom Inputs ***************************/

#define endl '\n'

void generate()
{
	auto low = rnd.next(num_low, num_high);
	auto high = rnd.next(num_low, num_high);

	if(low > high)
		swap(low, high);

	int digit = rnd.next(1, 9);
	int cnt = rnd.next(0, 20);

	cout << low << " ";
	cout << high << " ";
	cout << digit << " ";
	cout << cnt << endl;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	int t = rnd.next(t_low, t_high);
	cout << t << endl;

	for(int i = 0; i < t; i++)
		generate();

	return 0;
}

