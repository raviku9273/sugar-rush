#include<bits/stdc++.h>
using namespace std;

/********************* Custom Inputs ***************************/

const int n_low = (int)(1e3);
const int n_high = (int)(1e3);
const long long iv_low = (int)(1e6);
const long long iv_high = (int)(1e6);
const long long weight_low = 1;
const long long weight_high = 100;
const int p_low = 1;
const int p_high = (int)(1e3);
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
	std::uniform_int_distribution<long long> gen_array_weight(weight_low, weight_high);

	int n = gen_array_len(mt);
	
	vector<long long> a(n);

	for(int i = 0; i < n; i++)
		a[i] = gen_array_val(mt);

	vector<long long> weight(n);
	for(auto &ele : weight)
		ele = gen_array_weight(mt);

	cout << n << endl;
	for(auto ele : a)
		cout << ele << endl;

	cout << n << endl;
	for(auto ele : weight)
		cout << ele << endl;

	cout << gen_array_len(mt) << endl;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	global_seed = atoi(argv[1]);

	/* Seed STL's RAND */
	srand(atoi(argv[1]));

	generate_array(n_low, n_high, iv_low, iv_high);
	return 0;
}

