#include<bits/stdc++.h>
using namespace std;

#define v_pair vector<pair<int, int>>
#define v_v vector<vector<int>>

class ImageMatching
{
public:
	int row, col;
	vector<vector<int>> mat, grid;
	vector<vector<bool>> visited;

public:
	void dfs(int i, int j, v_v &source, v_pair &curr);
	void solve();
};

void ImageMatching :: dfs(int i, int j, v_v &source, v_pair &curr)
{
	if(i < 0 or i >= row or j < 0 or j >= col)
		return;
	
	if(source[i][j] != 1)
		return;

	if(visited[i][j])
		return;
	
	visited[i][j] = true;
	curr.push_back(make_pair(i, j));
	
	dfs(i, j + 1, source, curr); dfs(i, j - 1, source, curr);
	dfs(i + 1, j, source, curr); dfs(i - 1, j, source, curr);
}

void ImageMatching :: solve()
{
	/* Assume that mat, grid, row, col are set up */

	vector<v_pair> first_c, second_c;

	visited.assign(row, vector<bool>(col, false));
	v_pair curr;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(mat[i][j] == 1 and not visited[i][j])
			{
				dfs(i, j, mat, curr);
				first_c.push_back(curr);
				curr.clear();
			}
		}
	}
	
	visited.assign(row, vector<bool>(col, false));
	curr.clear();
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(grid[i][j] == 1 and not visited[i][j])
			{
				dfs(i, j, grid, curr);
				second_c.push_back(curr);
				curr.clear();
			}
		}
	}

	for(auto &ele : first_c)
		sort(ele.begin(), ele.end());

	for(auto &ele : second_c)
		sort(ele.begin(), ele.end());

	sort(first_c.begin(), first_c.end());
	sort(second_c.begin(), second_c.end());

	vector<v_pair> res;
	set_intersection(first_c.begin(), first_c.end(),
			second_c.begin(), second_c.end(),
			back_inserter(res));
	
	cout << (int)(res.size()) << endl;
}

int main()
{
	int n;
	cin >> n;

	ImageMatching obj;
	obj.row = n; obj.col = n;

	obj.mat.assign(n, vector<int>(n, 0));
	obj.grid.assign(n, vector<int>(n, 0));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;

			obj.mat[i][j] = (ch == '1');
		}
	}

	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;

			obj.grid[i][j] = (ch == '1');
		}
	}
	
	obj.solve();

	return 0;
}
