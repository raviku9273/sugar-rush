#include <bits/stdc++.h>
using namespace std;

int winningNumber(vector<int> firstNumber, vector<int> secondNumber)
{
	int n = firstNumber.size();

	vector<int> left(n), right(n);

	for(int i = 0; i < n; i++)
	{
		left[i] = min(firstNumber[i], secondNumber[i]);
		right[i] = max(firstNumber[i], secondNumber[i]);
	}

	map<int, int> covered;
	for(int i = 0; i < n; i++)
	{
		covered[left[i]] += 1;
		covered[right[i] + 1] -= 1;
	}

	int pref_sum = 0, mx = 0;

	for(auto ele : covered)
	{
		pref_sum += ele.second;
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
