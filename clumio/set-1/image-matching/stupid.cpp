#include<bits/stdc++.h>
using namespace std;

#define v_pair vector<pair<int, int>>

class ImageMatching
{
public:
	int row, col;
	vector<vector<int>> mat;
public:
	void dfs(int i, int j, v_pair &curr);
	vector<v_pair> process();
};

void ImageMatching :: dfs(int i, int j, v_pair &curr)
{
	if(i < 0 or i >= row or j < 0 or j >= col)
		return;
	
	if(mat[i][j] != 1)
		return;

	mat[i][j] = 0;
	curr.push_back(make_pair(i, j));
	
	dfs(i, j + 1, curr); dfs(i, j - 1, curr);
	dfs(i + 1, j, curr); dfs(i - 1, j, curr);
}

vector<v_pair> ImageMatching :: process()
{
	int n; cin >> n;

	row = n, col = n;
	mat.resize(row, vector<int>(col, 0));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char ch; cin >> ch;
			mat[i][j] = (ch == '1');
		}
	}

	vector<v_pair> collection;
	v_pair curr;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(mat[i][j] == 1)
			{
				dfs(i, j, curr);
				collection.push_back(curr);
				curr.clear();
			}
		}
	}
	

	for(auto &ele : collection)
		sort(ele.begin(), ele.end());
	
	sort(collection.begin(), collection.end());

	return collection;
}

void solve()
{
	ImageMatching first_obj;
	auto first = first_obj.process();

	ImageMatching second_obj;
	auto second = second_obj.process();

	vector<v_pair> res;

	set_intersection(first.begin(), first.end(),
			second.begin(), second.end(),
			back_inserter(res));

	cout << (int)res.size() << endl;
}

int main()
{
	solve();
	return 0;
}
