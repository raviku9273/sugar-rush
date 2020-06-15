#include<bits/stdc++.h>
using namespace std;
/* Notations
 * 1) 'v' stands for vertex
 * 2) 'low[v]' and 'high[v]' represents the interval the vertex 'v' is controlling
 * 3) 'left' and 'right' represents the interval that we are dealing with
 * 4) Always pass 'v' as the last argument to enable function overloading 
 */

class SegTree
{
public:
	vector<int> low, high;
	vector<long long> tree;
public:
	SegTree(int n);
	void init(int left, int right, int v);
	void build(vector<long long> &a, int v);
	void update(int ind, long long new_val, int v);
	long long query(int left, int right, int v);
};

SegTree :: SegTree(int n)
{
	low.resize(4*n + 1);
	high.resize(4*n + 1);
	tree.resize(4*n + 1);
	init(0, n-1, 1);
}

void SegTree :: init(int left, int right, int v = 1)
{
	low[v] = left;
	high[v] = right;

	if(left == right)
		return;

	int mid = (left + right)/2;
	init(left, mid, 2*v);
	init(mid + 1, right, 2*v + 1);
}

void SegTree :: build(vector<long long> &a, int v = 1)
{
	if(low[v] == high[v])
	{
		tree[v] = a[low[v]];
		return;
	}

	build(a, 2*v);
	build(a, 2*v + 1);

	tree[v] = max(tree[2*v], tree[2*v + 1]);
}

void SegTree :: update(int ind, long long new_val, int v = 1)
{
	if(ind < low[v] or high[v] < ind)
		return;
	
	if(low[v] == high[v])
	{
		tree[v] = new_val;
		return;
	}

	update(ind, new_val, 2*v);
	update(ind, new_val, 2*v + 1);

	tree[v] = max(tree[2*v], tree[2*v + 1]);
}

long long SegTree :: query(int left, int right, int v = 1)
{
	/* Completely Disjoint */
	if(right < low[v] or high[v] < left)
		return 0;

	/* Completely Contained. */
	if(left <= low[v] and high[v] <= right)
		return tree[v];

	long long left_res = query(left, right, 2*v);
	long long right_res = query(left, right, 2*v + 1);

	return max(left_res, right_res);
}

void Flowers(vector<long long> &a, vector<int> &h)
{
	int n = a.size();

	vector<long long> dp(n, 0);

	SegTree segtree(n);
	segtree.build(dp);

	/* dp[height] represents the maximum beauty of a subsequence which ends with height 'height' */
	for(int i = 0; i < n; i++)
	{
		int curr_height = h[i];

		// Always update the seg tree parallely
		dp[curr_height] = a[i];
		segtree.update(curr_height, dp[curr_height]);

		long long prefix_max = 0;

		/*
		for(int j = 0; j < curr_height; j++)
			prefix_max = max(prefix_max, dp[j]);
		*/
		
		if( curr_height == 0)
			continue;
		
		prefix_max = segtree.query(0, curr_height - 1);

		dp[curr_height] += prefix_max;
		segtree.update(curr_height, dp[curr_height]);
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> h(n);
	for(auto &ele : h)
	{
		cin >> ele;
		ele--;
	}
	
	vector<long long> a(n);
	for(auto &ele : a)
		cin >> ele;

	Flowers(a, h);
	return 0;
}

