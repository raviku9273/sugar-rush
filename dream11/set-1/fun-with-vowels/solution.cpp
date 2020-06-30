#include <bits/stdc++.h>
using namespace std;

int fun_with_vowels(string str)
{
	int n = str.length();

	vector<int> dp_a(n), dp_e(n), dp_i(n), dp_o(n), dp_u(n);

	dp_u[n - 1] = (str[n - 1] == 'u');

	for(int ind = n - 2; ind >= 0; ind--)
	{
		/* Fill the DP for 'u' */
		dp_u[ind] = (str[ind] == 'u') + dp_u[ind + 1];

		
		/* Fill the DP for 'o' */
		if(str[ind] == 'o')
		{
			int max_val = max(dp_o[ind + 1], dp_u[ind + 1]);

			if(max_val)
				dp_o[ind] = 1 + max_val;
		}
		else
		{
			dp_o[ind] = dp_o[ind + 1];
		}

		/* Fill the DP for 'i' */
		if(str[ind] == 'i')
		{
			int max_val = max(dp_i[ind + 1], dp_o[ind + 1]);

			if(max_val)
				dp_i[ind] = 1 + max_val;
		}
		else
		{
			dp_i[ind] = dp_i[ind + 1];
		}

		/* Fill the DP for 'e' */
		if(str[ind] == 'e')
		{
			int max_val = max(dp_e[ind + 1], dp_i[ind + 1]);

			if(max_val)
				dp_e[ind] = 1 + max_val;
		}
		else
		{
			dp_e[ind] = dp_e[ind + 1];
		}

		/* Fill the DP for 'a' */
		if(str[ind] == 'a')
		{
			int max_val = max(dp_a[ind + 1], dp_e[ind + 1]);

			if(max_val)
				dp_a[ind] = 1 + max_val;
		}
		else
		{
			dp_a[ind] = dp_a[ind + 1];
		}
	}

	return dp_a[0];
}

int main()
{
	string str;
	cin >> str;

	cout << fun_with_vowels(str) << endl;
	return 0;
}
