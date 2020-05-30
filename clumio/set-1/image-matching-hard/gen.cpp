#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = rand(500, 1000);

	vector<vector<int>> mat, grid;

	mat.resize(n, vector<int>(n, 0));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = rand(0, 1);

	grid = mat;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(rand(0, 1))
				grid[i][j] = rand(0, 1);

	cout << n << endl;
	for(auto &row_vec : mat)
	{
		for(auto ele : row_vec)
			cout << ele;

		cout << endl;
	}

	cout << n << endl;
	for(auto &row_vec : grid)
	{
		for(auto ele : row_vec)
			cout << ele;

		cout << endl;
	}

	return 0;
}
