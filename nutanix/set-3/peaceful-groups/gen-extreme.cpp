#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	
	int n = 1e5;
	cout << n << endl;

	set<int> color_set; 

	vector<int> color_list = {100, 1000};
	int total_color = color_list[rand(0, 1)];

	while((int)(color_set.size() != total_color))
	{
		color_set.insert(rand(1, 2*(int)(1e5)));
	}
	
	vector<int> color_vec;
	for(auto ele : color_set)
		color_vec.push_back(ele);

	for(int i = 0; i < n; i++)
		cout << color_vec[rand(0, total_color - 1)] << " ";

	cout << endl;
	return 0;
}
