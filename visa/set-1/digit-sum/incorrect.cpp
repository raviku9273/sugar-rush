/*
copyright@prabhat7298
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pi pair<int ,int >
#define pl pair<ll ,ll >
#define pb push_back
#define vl vector <long long int >
#define vi vector <int >
#define vp vector <pi>
#define mod 1000000007
#define eps 1e-9
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define _ <<" "<<
#define forn(x,	n) for(int x = 0; x < n ;++ x) 
#define forn1n(x,n) for(int x = 1; x <= n ;++ x)
#define forn1(x,n) for(int x = 1; x < n ;++ x)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#pragma GCC optimize ("Ofast")
void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<","<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<" ";out<<*it;}out<<"";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}

ll a,b,n;
const int N = 18+1;
const int  S = 165;
ll dp[N][2][S];
vector<int>digits;
vl cnt(S);
void store(ll x)
{
	digits.clear();
	while(x)
	{
		digits.pb(x%10);
		x/=10;
	}
	reverse(all(digits));
	n = digits.size();
}

ll solve(int pos, int flag, ll sum)
{
	if(pos==n)
		{
			cnt[sum]++;
			return sum;
		}
	if(dp[pos][flag][sum]!=-1)
		return dp[pos][flag][sum];
	int limit;
	if(flag==0)
		limit = digits[pos];
	else
		limit = 9;
	ll ans = 0;
	for(int i=0;i<=limit;i++)
	{
		int newflag=flag;
		if(flag==0&&i<digits[pos])
			newflag = 1;
		ans += solve(pos+1,newflag,sum+i);
	}
	return dp[pos][flag][sum]=ans;
}
int main(){
	IOS
	int t;
	/* cin>>t; */
	t = 1;
	while(t--)
	{
		cin>>a>>b;
		if(a==-1&&b==-1)
			break;
		a-=1;
		store(a);
		memset(dp,-1,sizeof(dp));
		ll ans1 = solve(0,0,0);
		auto acnt = cnt;
		store(b);
		fill(all(cnt),0);
		memset(dp,-1,sizeof(dp));
		ll ans2 = solve(0,0,0);
		auto bcnt = cnt;
		vector<ll>tcnt;
		forn(i,S)
		{
			tcnt.pb(bcnt[i]-acnt[i]);
		}
		
		ll sum = max_element(all(tcnt))-tcnt.begin();
		ll maxe = tcnt[sum];
		int ways=0;
		forn(i,S)
			if(tcnt[i]==maxe)
				ways++;
		cout<<maxe<< endl;
		cout << ways<<endl;
	}
	
 
	return 0;	
}
