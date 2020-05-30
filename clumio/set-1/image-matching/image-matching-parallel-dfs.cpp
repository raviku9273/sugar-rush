#include<bits/stdc++.h>
using namespace std;

class ImageMatching
{
public:
	int n;
	vector<vector<int>> mat, grid;

public:
	void normal_dfs(int i, int j, vector<vector<int>> &source);
	void parallel_dfs(int i, int j, bool &flag);
	void solve();
	void input();
};

void ImageMatching :: normal_dfs(int i, int j, vector<vector<int>> &source)
{
	if(i < 0 or i >= n or j < 0 or j >= n)
		return;

	if(source[i][j] == 0)
		return;

	source[i][j] = 0;

	normal_dfs(i + 1, j, source); normal_dfs(i - 1, j, source);
	normal_dfs(i, j + 1, source); normal_dfs(i, j - 1, source);
}

void ImageMatching :: parallel_dfs(int i, int j, bool &flag)
{
	if(i < 0 or i >= n or j < 0 or j >= n)
		return;

	if(mat[i][j] == 0 and grid[i][j] == 0)
		return;

	if(mat[i][j] != grid[i][j])
	{
		flag = false;
		normal_dfs(i, j, mat);
		normal_dfs(i, j, grid);
		return;
	}

	mat[i][j] = 0;
	grid[i][j] = 0;

	parallel_dfs(i + 1, j, flag); parallel_dfs(i - 1, j, flag);
	parallel_dfs(i, j + 1, flag); parallel_dfs(i, j - 1, flag);
}

void ImageMatching :: solve()
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(mat[i][j] or grid[i][j])
			{
				bool flag = true;
				parallel_dfs(i, j, flag);
				
				if(flag)
					count++;
			}
		}
	}

	cout << count << endl;
}

void ImageMatching :: input()
{
	cin >> n;

	mat.resize(n, vector<int>(n, 0));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;

			mat[i][j] = (ch == '1');
		}
	}

	cin >> n;
	grid.resize(n, vector<int>(n, 0));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;

			grid[i][j] = (ch == '1');
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ImageMatching obj;
	obj.input();
	obj.solve();

	return 0;
}
