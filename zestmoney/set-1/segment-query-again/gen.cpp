#include "testlib.h"
#include <iostream>

/*************************** Custom Inputs ******************/

const int n_low = 200;
const int n_high = 200;
const long long leaves_low = 1e15;
const long long leaves_high = 1e16;
const int q_low = 1e5;
const int q_high = 1e5;
const int day_low = 1;
const int day_high = 120;
const int p_low = 30;
const int p_high = 100;

/************************************************************/
using namespace std;

#define endl '\n'

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    
    int n = rnd.next(n_low, n_high);

    vector<long long> a(n);
    for(auto &ele : a)
	    ele = rnd.next(leaves_low, leaves_high);

    int q = rnd.next(q_low, q_high);

    vector<int> days(q), left(q), right(q);

    for(int i = 0; i < q; i++)
    {
	    days[i] = rnd.next(day_low, day_high);
	    left[i] = rnd.next(1, n);
	    right[i] = rnd.next(1, n);

	    if(left[i] > right[i])
		    swap(left[i], right[i]);
    }

    cout << n << endl;
    for(auto &ele : a)
	    cout << ele << endl;

    int percentage = rnd.next(p_low, p_high);
    cout << percentage << endl;

    cout << q << endl;
    for(auto &ele : days)
	    cout << ele << endl;

    cout << q << endl;
    for(auto &ele : left)
	    cout << ele << endl;

    cout << q << endl;
    for(auto &ele : right)
	    cout << ele << endl;

    return 0;
}
