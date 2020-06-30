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

const int MOD = 1e9 + 7;
const int maxn = 2519;
int dp[maxn][maxn][2];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s; cin >> s;
	int n,x,y; cin >> n >> x >> y;
	int ss = sz(s);
	dp[0][x][0] = 1;
	rep(i,ss){
		rep(j,n+1){
			dp[i+1][j][0] = dp[i][j][0];
			dp[i+1][j][1] = dp[i][j][1];
			if(j ==0 && s[i] == 'l'){
				dp[i+1][j][0] = (dp[i][j+1][0] + dp[i][j+1][1])%MOD;
			}
			if(j == n && s[i] == 'r'){
				dp[i+1][j][1] = (dp[i][j-1][0] + dp[i][j-1][1])%MOD;
			}else{
				if(s[i] == 'r'){
					dp[i+1][j][1] = (dp[i][j-1][0] + dp[i][j-1][1])%MOD;
				}else{
					dp[i+1][j][0] = (dp[i][j+1][0] + dp[i][j+1][1])%MOD;
					if(j == x) dp[i+1][j][0] = (dp[i+1][j][0] + 1)%MOD;
				}
			}
			//cout << i+1 << " " << j << " " << 0 << " " << dp[i+1][j][0] << endl;
			//cout << i+1 << " " << j << " " << 1 << " " << dp[i+1][j][1] << endl;
		}
	}
	cout << (dp[ss][y][1] + dp[ss][y][0])%MOD << endl;
	return 0;
}
 
