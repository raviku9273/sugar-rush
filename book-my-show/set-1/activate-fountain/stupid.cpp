
/* Lavish Gupta */
#include <bits/stdc++.h>
using namespace std;
/*********************** Template Begins ****************************/
/* Return an integer denoting the minimum number of fountains that must be activated */
#define ll long long
#define fo(i, n) for(ll i= 0 ; i < n ; i++)
int fountainActivation(vector<int> &locations)
{
    ll n = locations.size() ;
    vector<pair<ll ,ll> > v ;
    fo(i , n)
    {
        ll l = max((ll)1 , (i + 1) - locations[i]) ;
        ll r = min(n , (i+1) + locations[i]) ;
        v.push_back(make_pair(l , -r)) ;
    }
    sort(v.begin() , v.end()) ;
    fo(i , n)
    {
        v[i].second *= -1 ;
        if(i)
            v[i].second = max(v[i].second , v[i-1].second) ;
    } 
    /*fo(i , n)
    {
        cout << v[i].first << ' ' << v[i].second << endl ;
    }
    cout << endl ;*/
    ll curr = 1 , ans = 0 ;
    while(curr <= n)
    {
        pair<ll ,ll> g = make_pair(curr , 0) ;
        ll ind = lower_bound(v.begin() , v.end() , g) - v.begin() ;
        if(v[ind].first > curr)
            ind-- ;
        //cout << "ind = " << ind << endl ;
        curr = v[ind].second + 1 ;
        ans++ ;
    }
    return ans ;
}
/*********************** Template Ends ****************************/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &ele : a)
        cin >> ele;
    cout << fountainActivation(a) << endl;
    return 0;
}
