#include <iostream>
#include "testlib.h"

using namespace std;

/********************* Custom Inputs ***************************/
const int half_len_low = 1;
const int half_len_high = 500 - 4;
/********************* Custom Inputs ***************************/

#define endl '\n'

void gen_string()
{
	int len = 2*rnd.next(half_len_low, half_len_high);
	
	vector<char> a;

	while((int)a.size() != len)
	{
		char curr = 'a' + rnd.next(0, 25);
		a.push_back(curr);
		a.push_back(curr);
	}

	if(rnd.next(0, 1))
	{
		char curr = 'a' + rnd.next(0, 25);
		a.push_back(curr);
	}

	shuffle(a.begin(), a.end());

	for(auto ele : a)
		cout << ele;
}

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);

	gen_string();
	return 0;
}

