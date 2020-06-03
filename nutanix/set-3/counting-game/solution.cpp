#include<bits/stdc++.h>
using namespace std;

/* Corner Cases to Handle
 * 1) num ends in a zero (includes the leader 1000...0)
 * 2) num and the leader have the same first half (No Reversal Needed)
 * 3) 1 Digit Number
 * 4) Odd Length Number --> Should we include middle element?
 */

/* Returns 1000...0 (#zero + #one == len) */
long long leader(int len)
{
	long long num = 1;
	for(int i = 0; i < (len - 1); i++)
		num *= 10;

	return num;
}

long long solve(long long num)
{
	// A single digit number
	if(num <= 9)
		return num;

	string num_str = to_string(num);
	int len = num_str.length();
	
	// If the string ends in zero, get to 999...9 first, and increment
	if( num%10 == 0)
		return 1 + solve(num - 1);

	/* Base is the nearest 1000...0 */
	long long base = leader(len);
	long long cost = solve(base);
	
	// Don't include the middle element. Why? 
	string num_first_half = num_str.substr(0, len/2);
	string num_second_half = num_str.substr(len/2);

	string base_first_half = to_string(base).substr(0, len/2);

	/* Handle the case num = (10000 x ....) */
	if( num_first_half == base_first_half)
	{
		cost += stoll( num_second_half );
		return cost;
	}
	
	reverse( num_first_half.begin(), num_first_half.end());
	cost += stoll(num_first_half);

	// One Reversal
	cost += 1;

	cost += stoll(num_second_half);

	// A bonus. (As the last digit was 1 instead of 0)
	cost -= 1;

	return cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		long long n;
		cin >> n;

		cout << solve(n) << endl;
	}

	return 0;
}
