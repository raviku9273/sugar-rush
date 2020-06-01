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
	row = rand(1, (int)(1e5));
	col = rand(1, (int)(1e5));
	
	cout << row << " ";
	cout << col << endl;

	vector<int> break_row;
	for(int i = 1; i <= row; i++)
		if(rand(0, 1))
			break_row.push_back(i);

	vector<int> break_col;
	for(int j = 1; j <= col; j++)
		if(rand(0, 1))
			break_col.push_back(j);

	cout << (int)break_row.size() << endl;
	for(auto &ele : break_row)
		cout << ele << " ";

	cout << endl;

	cout << (int)break_col.size() << endl;
	for(auto &ele : break_col)
		cout << ele << " ";

	cout << endl;
	return 0;
}
