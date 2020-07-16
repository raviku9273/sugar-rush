#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int winningNumber(vector<int> firstNumber, vector<int> secondNumber)
{
	int n = firstNumber.size();

	vector<int> left(n), right(n);

	for(int i = 0; i < n; i++)
	{
		left[i] = min(firstNumber[i], secondNumber[i]);
		right[i] = max(firstNumber[i], secondNumber[i]);
	}

	vector<pair<int, int>> store;

	/* Upon Tie : Arrival should be given more priority. Think Why? */
	/* Hence, we are giving arrival a low number rather than the reverse */
	for(auto ele : left)
		store.push_back(mp(ele, 0));

	for(auto ele : right)
		store.push_back(mp(ele, 1));

	sort(store.begin(), store.end());

	int pref_sum = 0, mx = 0;

	for(auto ele : store)
	{
		if(ele.second == 0)
			pref_sum += 1;
		else
			pref_sum -= 1;

		mx = max(mx, pref_sum);
	}

	return mx;
}

int main()
{
	int n;
	cin >> n;

	vector<int> firstNumber(n);
	for(auto &ele : firstNumber)
		cin >> ele;

	cin >> n;
	vector<int> secondNumber(n);
	for(auto &ele : secondNumber)
		cin >> ele;

	int res = winningNumber(firstNumber, secondNumber);
	cout << res << endl;

	return 0;
}
