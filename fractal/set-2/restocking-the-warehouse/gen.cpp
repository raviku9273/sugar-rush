#include<bits/stdc++.h>
using namespace std;

/********************* Custom Inputs ***************************/
const int n_low = 1;
const int n_high = (int)(1e5);
const long long item_low = 1;
const long long item_high = (long long)(1e9);
/********************* Custom Inputs ***************************/

#define endl '\n'

int global_seed;

int rand(int a, int b)
{
	return a + rand() % (b - a + 1);
}

void generate_array(int len_low, int len_high, long long val_low, long long val_high)
{
	/* Seed the Mersenne Twister */
	std::mt19937 mt(global_seed);

	/* Probability Distribution */
	std::uniform_int_distribution<int> gen_array_len(len_low, len_high);
	std::uniform_int_distribution<long long> gen_array_val(val_low, val_high);

	int n = gen_array_len(mt);
	
	vector<long long> a(n);

	for(int i = 0; i < n; i++)
		a[i] = gen_array_val(mt);

	cout << n << endl;
	for(auto ele : a)
		cout << ele << endl;

	cout << gen_array_val(mt) << endl;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	global_seed = atoi(argv[1]);

	/* Seed STL's RAND */
	srand(atoi(argv[1]));
		
	generate_array(n_low, n_high, item_low, item_high);
	return 0;
}

