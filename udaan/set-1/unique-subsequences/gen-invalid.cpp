#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int t_low = 1;
const int t_high = 10;
const int len_low = 1;
const int len_high = 1e5;
const int rep_low = 0;
const int rep_high = 3;
/********************* Custom Inputs ***************************/

#define endl '\n'

void generate()
{
	string str = "";
	for(char c = 'a'; c <= 'z'; c++)
	{
		int rep = rnd.next(rep_low, rep_high);
		for(int i = 0; i < rep; i++)
			str += c;
	}

	shuffle(str.begin(), str.end());

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

