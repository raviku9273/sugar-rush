#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e6 + 6;

vector<int> spf;
vector<int> C, D;

/* Bounded by O(n*loglog(n)) (if implemented properly) */
void sieve_spf()
{
	spf.assign(max_n, 1);

	/* This step is not required in Sieve. Think Why? */
	for(int num = 1; num < max_n; num++)
		spf[num] = num;

	for(int num = 2; num < max_n; num++)
	{
		if(spf[num] != num)
			continue;

		for(int multiple = 2*num; multiple < max_n; multiple += num)
		{
			if(spf[multiple] == 1)
				spf[multiple] = num;
		}
	}
}

/* Bounded by O(n) */
void compute_C()
{
	C.assign(max_n, 0);

	for(int num = 2; num < max_n; num++)
		C[num] = 1 + C[num/spf[num]];
}

/* Bounded by O(n) */
void compute_D()
{
	D.assign(max_n, 0);

	for(int num = 1; num < max_n; num++)
		D[num] = D[num - 1] + C[num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve_spf();
	compute_C();
	compute_D();

	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int num;
		cin >> num;

		cout << D[num] << '\n';
	}

	return 0;
}
