#include <bits/stdc++.h>
using namespace std;

int shortest_unsorted(vector<int> &a)
{
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for(auto &ele : a)
		scanf("%d", &ele);

	int res = shortest_unsorted(a);
	printf("%d\n", res);

	return 0;
}
