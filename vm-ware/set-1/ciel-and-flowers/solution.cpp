#include<bits/stdc++.h>
using namespace std;

/* This is what I call elegant. Tricky Question. Concise Editorial. No Confusion. */

/* Theorem : There always exist an optimal solution with less than 3 mixing bouqets.
   Proof : As soon as you get the third mixing bouqet, convert it to 3 monchrome bouqets.
*/

int ciel_and_flowers(int r, int g, int b)
{
	// This workaround is not needed with tuples
	int min_flowers = min(r,g);
	min_flowers = min(min_flowers, b);

	// Case 1 : No Mixing bouqet
	int no_mix = r/3 + g/3 + b/3;

	// Case 2 : 1 Mixing Bouqet
	int one_mix = 0;

	if(min_flowers >= 1)
		one_mix += 1;

	one_mix += (r-1)/3 + (g-1)/3 + (b-1)/3;

	// Case 3 : 2 Mixing Bouqet
	int two_mix = 0;
	
	// Bug in the first attempt. Wrote two_mix++
	if(min_flowers >= 2)
		two_mix += 2;

	two_mix += (r-2)/3 + (g-2)/3 + (b-2)/3;
	
	// This workaround is not required with tuples
	int res = max(no_mix, one_mix);
	res = max(res, two_mix);

	return res;
}

int main()
{
	int r,g,b;
	cin >> r >> g >> b;

	cout << ciel_and_flowers(r,g,b);

	return 0;
}
