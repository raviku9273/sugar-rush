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
//ll ncr(ll n , ll r){;if(n < r|| (n < 0) || (r < 0)) return 0 ; return ((((fact[n] * inverse(fact[r] , z)) % z) * inverse(fact[n-r] , z)) % z);}
void swap(ll&a , ll&b){ll c = a ; a = b ; b = c ; return ;}
//ll ncr(ll n , ll r){if(n < r || n < 0 || r < 0) return 0 ; return fact[n]/(fact[r]*fact[n-r]) ;}
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
ll ncr[2000][20] ;

ll get_cnt(ll r , ll n)
{
    // x1 + x2 + x3 ... + xr  = n ;
    if(r == 0 && n == 0)
        return 1;
    if(r == 0 && n != 0)
        return 0;
    if(n < 0)
        return 0 ;
    if(n+r-1 < 0 || r-1 < 0 || n+r-1 < r-1)
        return 0 ;
    ll tot = 0 ;
    for(ll i = 0 ; i <= r ; i++)
    {
        ll curr_n = n - (10*i) ;
        if(curr_n < 0)
            break ;
        ll curr_ans = ncr[curr_n+r-1][r-1] ;
        curr_ans *= ncr[r][i] ;
        if(i%2 == 0)
            tot += curr_ans ;
        else
            tot -= curr_ans ;
    }
    return tot ;
}

void get_ans(string &str,ll ind , ll sum , ll &ans)
{
    if(ind == str.size())
    {
        if(sum == 0)
            ans++ ;
        return ;
    }

    if(sum < 0)
        return ;

    ll curr_dig = (ll)(str[ind] - '0') ;
    ll siz = (ll)(str.size()) ;

    if(9*siz < sum)
        return ;

    fo(i , curr_dig)
    {
        ans += get_cnt(siz-ind-1 , sum-i) ;
    }

    get_ans(str , ind+1 , sum -  curr_dig , ans) ;
    return ;
}

void solve()
{
    ll loww , highh ;
    cin >> loww >> highh ;
    loww-- ;
    string low , high ;
    low = to_string(loww) ;
    high = to_string(highh) ;

    //cout << low << ' ' << high << endl ;

    ll ans_1[2000] , ans_2[2000]  , ans[2000] ;
    ll maxi = 0 , cnt = 0 ;
    fo(i , 2000)
    {
        ans_1[i] = ans_2[i] = ans[i] = 0 ;
        get_ans(high , 0 , i , ans_1[i]) ;
        get_ans(low , 0 , i , ans_2[i]) ;
        ans[i] = ans_1[i] - ans_2[i] ;
        maxi = max(maxi , ans[i]) ;
    }
    
    //cout << endl ;    
    
    fo(i , 2000)
    {
        if(ans[i] == maxi)
            cnt++ ;
    }
    cout << cnt << '\n' << maxi << endl ;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll t ;
    //cin >> t ;
    t = 1 ;
   
    
    fo(i , 2000)
    {
        fo(j , 20)
            ncr[i][j] = 0 ;
    }
    fo(i , 2000)
        ncr[i][0] = 1 ;

    for(ll i = 1 ; i < 2000 ; i++)
    {
        for(ll j = 1 ; j < 20 ; j++)
        {
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j] ;
            ncr[i][j] %= z ;
        }
    }    
    
    while(t--)
    {
        solve() ;
    }
 
    return 0;
}
