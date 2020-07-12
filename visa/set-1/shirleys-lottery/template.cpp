#include <bits/stdc++.h>
using namespace std;

int winningNumber(vector<int> firstNumber, vector<int> secondNumber)
{
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
