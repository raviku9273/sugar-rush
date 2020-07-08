#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>

/* Notations
 * 1) 'v' stands for vertex
 * 2) 'low[v]' and 'high[v]' represents the interval the vertex 'v' is controlling
 * 3) 'left' and 'right' represents the interval that we are dealing with
 * 4) Always pass 'v' as the last argument to enable default arguments
 */

/* 1. Build a min-segment-tree
 * 2. Find the first element smaller than or equal to key
 */

const long long inf = 1e16;

class SegTree
{
	vector<int> low, high;
	vector<long long> tree;
public:
	SegTree(int n);
	void init(int left, int right, int v);
	void build(vector<long long> &a, int v);
	void update(int ind, long long new_val, int v);
	int query(int left, int right, long long key, int v);
};

SegTree :: SegTree(int n)
{
	low.resize(4*n + 1);
	high.resize(4*n + 1);
	tree.resize(4*n + 1);
	init(0, n - 1, 1);
}

/* Make vertex 'v' control the interval [left, right] */
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

/* Update the tree value of each node */
void SegTree :: build(vector<long long> &a, int v = 1)
{
	if(low[v] == high[v])
	{
		tree[v] = a[low[v]];
		return;
	}

	build(a, 2*v);
	build(a, 2*v + 1);

	tree[v] = min(tree[2*v] , tree[2*v + 1]);
}

void SegTree :: update(int ind, long long new_val, int v = 1)
{
	if(ind < low[v] or ind > high[v])
		return;

	if(low[v] == high[v])
	{
		tree[v] = new_val;
		return;
	}

	update(ind, new_val, 2*v);
	update(ind, new_val, 2*v + 1);

	tree[v] = min(tree[2*v], tree[2*v + 1]);
}

int SegTree :: query(int left, int right, long long key, int v = 1)
{
	/* Be careful with 'and', 'or' */

	/* Completely Disjoint */
	if(right < low[v] or left > high[v])
		return -1;

	/* Vertex is completely contained */
	/* Also handles leaf nodes */
	if(low[v] >= left and high[v] <= right)
	{
		if(tree[v] > key)
			return -1;

		/* Reach the leaf node */
		while(low[v] != high[v])
		{
			if(tree[2*v] <= key)
				v = 2*v;
			else
				v = 2*v + 1;
		}

		return low[v];
	}

	
	/* Partial Overlap */
	auto left_ans = query(left, right, key, 2*v);
	auto right_ans = query(left, right, key, 2*v + 1);

	if(left_ans != -1)
		return left_ans;

	return right_ans;
}

void load_balancing(vector<pll> &arr_load, int n)
{
	sort(arr_load.begin(), arr_load.end());

	vector<long long> a(n), tot_load(n);

	SegTree segtree(n);
	segtree.build(a);

	int i_free = 0;
	for(auto ele : arr_load)
	{
		auto curr_time = ele.first;
		auto curr_load = ele.second;

		int nxt = segtree.query(i_free, n - 1, curr_time);

		if(nxt == -1)
			nxt = segtree.query(0, i_free, curr_time);

		if(nxt == -1)
			continue;


		tot_load[nxt] += curr_load;

		auto next_free_time = curr_time + curr_load - 1;
		segtree.update(nxt, next_free_time);
	
		i_free = (nxt + 1)%n;
	}

	auto maximal = *max_element(tot_load.begin(), tot_load.end());

	vector<int> res;
	for(int i = 0; i < n; i++)
		if(tot_load[i] == maximal)
			res.push_back(i);

	for(auto &ele : res)
		cout << ele + 1 << endl;
}

int main()
{
	int tot_servers;
	cin >> tot_servers;

	int sz;
	cin >> sz;

	vector<pll> arr_load(sz);
	for(auto &ele : arr_load)
		cin >> ele.first;

	cin >> sz;
	for(auto &ele : arr_load)
		cin >> ele.second;

	load_balancing(arr_load, tot_servers);
	return 0;
}
