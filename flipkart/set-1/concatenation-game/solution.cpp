#include <bits/stdc++.h>
using namespace std;

bool compare(string &small, string &big)
{
	string left_conc = small + big;
	string right_conc = big + small;

	if(left_conc > right_conc)
		return true;

	return false;
}

void concatenationGame(vector<long long> &a)
{
	vector<string> collection;

	for(auto ele : a)
		collection.push_back(to_string(ele));

	sort(collection.begin(), collection.end(), compare);
	for(auto ele : collection)
		cout << ele;

	cout << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long> a(n);
	for(auto &ele : a)
		cin >> ele;

	concatenationGame(a);
	return 0;
}


