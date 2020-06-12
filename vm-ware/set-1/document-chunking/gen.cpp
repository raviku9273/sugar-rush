#include<bits/stdc++.h>
using namespace std;

/********************* Custom Inputs ***************************/

/* Warning : Keep the first parameter high to avoid error */
const long long total_packets_low = 1e5;
const long long total_packets_high = 1e18;
const int uploaded_low = 0;
const int uploaded_high = 1e5;

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
}

void generate_permutation(int len_low, int len_high)
{
	/* Seed the Mersenne Twister */
	std::mt19937 mt(global_seed);

	/* Probabilitiy Distribution */
	std::uniform_int_distribution<int> gen_array_len(len_low, len_high);

	int n = gen_array_len(mt);

	vector<int> perm(n + 1);
	for(int i = 1; i <= n; i++)
		perm[i] = i;

	random_shuffle(perm.begin() + 1, perm.end());

	cout << n << endl;

	for(int i = 1; i <= n; i++)
		cout << perm[i] << endl;
}

void generate()
{
	/* Seed the Mersenne Twister */
	std::mt19937 mt(global_seed);

	std::uniform_int_distribution<long long> gen_total_packets(total_packets_low, total_packets_high);

	long long total_packets = gen_total_packets(mt);

	std::uniform_int_distribution<long long> gen_packets(1, total_packets);
	std::uniform_int_distribution<int> gen_uploaded(uploaded_low, uploaded_high);

	int uploaded = gen_uploaded(mt);

	set<long long> collection;
	while( (int)collection.size() != 2*uploaded)
		collection.insert(gen_packets(mt));

	cout << total_packets << endl;
	cout << uploaded << endl;
	cout << 2 << endl;
	
	int counter = 0;
	for(auto ele : collection)
	{
		counter++;
		
		cout << ele << " ";
		if(counter%2 ==0)
			cout << endl;
	}
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	global_seed = atoi(argv[1]);

	/* Seed STL's RAND */
	srand(atoi(argv[1]));
		
	generate();
	return 0;
}

