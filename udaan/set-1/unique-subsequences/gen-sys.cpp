#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int t_low = 10;
const int t_high = 10;
const int len_low = 1e5;
const int len_high = 1e5;
/********************* Custom Inputs ***************************/

#define endl '\n'

void generate()
{
	string str = "";

	int len = rnd.next(len_low, len_high);
	for(int i = 0; i < len; i++)
		str += 'a' + rnd.next(0, 25);

	cout << str.length() << endl;
	cout << str << endl;
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

