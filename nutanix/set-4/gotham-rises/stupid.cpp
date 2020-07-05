#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> gr;
vector <bool> vis;

void dfs(int i){
	vis[i] = true;
	for(int j: gr[i]){
		if(!vis[j]){
			dfs(j);
		}
	}
	return;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--){
		int n, r, cc, cr; cin >> n >> r >> cc >> cr;
		gr.clear(); vis.clear();
		gr.resize(n);
		vis.resize(n,false);
		for(int i = 0; i < r; i++){
			int u,v; cin >> u >> v;
			u--; v--;
			gr[u].push_back(v);
			gr[v].push_back(u);
		}
		if(cc <= cr){
			cout << 1LL*n*cc << '\n';
			continue;
		}
		int tc = 0;
		for(int i = 0; i < n; i++){
			if(!vis[i]){
				tc++;
				dfs(i);
			}
		}

		cout << 1LL*tc*cc + 1LL*(n-tc)*cr << '\n';
	}	
	return 0;
}

