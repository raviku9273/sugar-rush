#define ll long long
#define dd long double
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
//#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<utility>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<bitset>
using namespace std ;
dd pi = acos(-1) ;
ll z =  1000000000000000003 ;
ll inf = 100000000000000000 ;
ll p1 = 37 ;
ll p2 = 53 ;
ll mod1 =  202976689 ;
ll mod2 =  203034253 ;
ll fact[21] ;
ll gdp(ll a , ll b){return (a - (a%b)) ;}
ll ld(ll a , ll b){if(a < 0) return -1*gdp(abs(a) , b) ; if(a%b == 0) return a ; return (a + (b - a%b)) ;} // least number >=a divisible by b
ll gd(ll a , ll b){if(a < 0) return(-1 * ld(abs(a) , b)) ;    return (a - (a%b)) ;} // greatest number <= a divisible by b
ll gcd(ll a , ll b){ if(b > a) return gcd(b , a) ; if(b == 0) return a ; return gcd(b , a%b) ;}
ll e_gcd(ll a , ll b , ll &x , ll &y){ if(b > a) return e_gcd(b , a , y , x) ; if(b == 0){x = 1 ; y = 0 ; return a ;}
ll x1 , y1 ; e_gcd(b , a%b , x1 , y1) ; x = y1 ; y = (x1 - ((a/b) * y1)) ; return e_gcd(b , a%b , x1 , y1) ;}
ll power(ll a ,ll b , ll p){if(b <0) return 0; if(b == 0) return 1 ; ll c = power(a , b/2 , p) ; if(b%2 == 0) return ((c*c)%p) ; else return ((((c*c)%p)*a)%p) ;}
ll inverse(ll a ,ll n){return power(a , n-2 , n) ;}
ll max(ll a , ll b){if(a > b) return a ; return b ;}
ll min(ll a , ll b){if(a < b) return a ; return b ;}
ll left(ll i){return ((2*i)+1) ;}
ll right(ll i){return ((2*i) + 2) ;}
//ll ncr(ll n , ll r){cout << n << ' ' << r << endl ;/*if(n < r|| (n < 0) || (r < 0)) return 0 ;*/ return ((((fact[n] * inverse(fact[r] , z)) % z) * inverse(fact[n-r] , z)) % z);}
void swap(ll&a , ll&b){ll c = a ; a = b ; b = c ; return ;}
ll ncr(ll n , ll r){if(n < r || n < 0 || r < 0) return 0 ; return fact[n]/(fact[r]*fact[n-r]) ;}
//ios_base::sync_with_stdio(0);
//cin.tie(0); cout.tie(0);

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// ordered_set s ; s.order_of_key(val)  no. of elements strictly less than val
// s.find_by_order(i)  itertor to ith element (0 indexed)
//__builtin_popcount(n) -> returns number of set bits in n
// ll seed;
//mt19937 rnd(seed=chrono::steady_clock::now().time_since_epoch().count()); // include bits

void function_(string &num , ll ind, ll d , ll cnt , ll &ans)
{
    if(ind == num.size())
    {
        if(cnt == 0)
            ans++ ;
        return ;
    }

    ll curr_dig = (ll)(num[ind] - '0') ;
    ll siz = (ll)(num.size()) ;

    if(curr_dig <= d)
    {
        ll poss_choice = curr_dig ;
        ans += (poss_choice * ncr(siz - ind - 1 , cnt) * power(9 , siz-ind-1-cnt , z)) ;
        function_(num , ind+1 , d , cnt - (curr_dig == d) , ans) ;
        return ;
    }

    ll poss_choice = curr_dig-1 ;
    ans += (poss_choice * ncr(siz - ind - 1 , cnt) * power(9 , siz-ind-1-cnt , z)) ;
    ans += (ncr(siz-ind-1 , cnt-1) * power(9 , siz-ind-cnt , z)) ;
    function_(num , ind+1 , d , cnt , ans) ;

    return ;
}

void function_0(string& num, ll ind , ll d , ll cnt , ll &ans)
{
    ll curr_dig = (ll)(num[ind] - '0') ;
    ll siz = (ll)(num.size()) ;

    if(ind >= siz)
        return ;

    // first digit 0
    {
        for(ll i = 1 ; i <= siz ; i++)
        {
            ll curr = (ncr(siz-i-1 , cnt) * power(9 , siz-i-cnt , z)) ;
            ans += curr ;
        }
    }

    // first digit non-0
    {
        ll poss_choice = curr_dig -1 ;
        ans += (poss_choice * ncr(siz-ind-1 , cnt) * power(9 , siz-ind-1-cnt , z)) ;
        function_(num , ind+1 , d , cnt , ans) ;
    }
    return ;
}

void solve()
{
    ll cnt , d ;
    ll loww ;
    string low , high ;
    cin >> loww >> high >> d >> cnt ;
    loww-- ;
    low = to_string(loww) ; 

    ll ans_1 = 0 , ans_2 = 0 , ans = 0;

    if(d == 0)
    {
        function_0(high , 0 , d , cnt , ans_1) ;
        function_0(low , 0 , d , cnt , ans_2) ;
        ans = (ans_1 - ans_2) ;
    }
    else
    {
        function_(high , 0 , d , cnt , ans_1) ;
        function_(low , 0 , d , cnt , ans_2) ;
        ans = (ans_1 - ans_2) ;
    }
    cout << ans << endl ;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt" , "r" , stdin) ;
    freopen("outputf.txt" , "w" , stdout) ;
    freopen("error.txt" , "w" , stderr) ;
    #endif
    
    ll t ;
    cin >> t ;
    //t = 1 ;
   
    fact[0] = 1 ;
    for(ll i = 1 ; i < 21 ; i++)
    {
        fact[i] = (fact[i-1]*i)%z ;
    }
    
    while(t--)
    {
        solve() ;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 
    return 0;
}
