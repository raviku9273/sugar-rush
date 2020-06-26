#include <bits/stdc++.h>
using namespace std;

int maximal_square(vector<vector<int>> &mat)
{
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int row, col;

	cin >> row >> col;

	vector<vector<int>> mat(row, vector<int>(col, 0));

	for(auto &row_vec : mat)
		for(auto &ele : row_vec)
			cin >> ele;

	cout << maximal_square(mat) << endl;
	return 0;
}

