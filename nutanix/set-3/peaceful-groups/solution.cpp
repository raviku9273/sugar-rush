#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	vi a(n); for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	map <int,int> mr;
	for(int i = 0; i < n; i++){
		mr[a[i]] = i;
	}
	int s = 0, m = 0;
	for(int i = 0; i < n; i++){
		m = max(mr[a[i]],m);
		if(m == i){
			map <int,int> mc;
			for(int j = i; j >= s; j--){
				mc[a[j]]++;
			}
			int mm = 0;
			for(auto it: mc){
				mm = max(mm, it.second);
			}
			ans += (i - s + 1) - mm;
			s = m + 1;
		}
	}
	cout << ans << endl;
	return 0;
}

