#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));

	int row, col;
	row = rand(1, (int)(1e3));
	col = rand(1, (int)(1e3));


	cout << row << " " << col << endl;

	vector<vector<int>> partial(row, vector<int>(col, 0));

	for(auto &row_vec : partial)
	{
		for(auto &ele : row_vec)
			cout << rand(0, 1000) << " ";

		cout << endl;
	}

	return 0;
}
