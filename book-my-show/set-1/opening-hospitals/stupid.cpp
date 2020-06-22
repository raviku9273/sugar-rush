#include <bits/stdc++.h>
using namespace std;
 
/*********************** Template Begins ****************************/
#define ll long long 
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define pub push_back
#define mp make_pair
 
int hospital(int n, vector<int> city_from, vector<int> city_to)
{
    if(n <= 2)
        return 1;
    vector<ll> adj[n] ;
    fo(i , city_from.size())
    {
        ll u = city_from[i] - 1 ;
        ll v = city_to[i] - 1 ;
        adj[u].pub(v) ;
        adj[v].pub(u) ;
    }
    ll deg[n] , lev[n];
    ll ans = 0 ;
    queue<ll> q ;
    ll vis[n] ;
    fo(i , n)
    {
        vis[i] = 0 ;
        lev[i] = -1 ;
        deg[i] = adj[i].size() ;
        if(deg[i] == 1)
        {
            q.push(i) ;
            vis[i] = 1 ;
            lev[i] = 0 ;
        }
 
    }
    /*fo(i , n)
    {
        cout << deg[i] << ' ';
    }
    cout << endl ;*/
    while(!q.empty())
    {
        ll u = q.front() ;
        q.pop() ;
        //cout << "u = " << u+1 << endl ;
        fo(i , adj[u].size())
        {
            ll v = adj[u][i] ;
            if(vis[v] == 0)
            {
                q.push(v) ;
                vis[v] = 1 ;
                lev[v] = lev[u]+1 ;
            }
        }
    }
    ll maxi = 0 , cnt = 0;
    fo(i , n)
        maxi = max(maxi , lev[i]) ;
    fo(i , n)
        if(lev[i] == maxi)
            cnt++ ;
    fo(i , n)
    {
        if(lev[i]%2 == 1 && lev[i] != maxi)
            ans++ ;
    }
    //cout << ans << endl ;
    if(maxi % 2 == 1)
    {
        if(maxi == 1)
            ans += cnt ;
        else
            ans++ ;
    }
    return ans ;
 
}
/*********************** Template Ends ****************************/
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int city_nodes, edges;
    cin >> city_nodes >> edges;
 
    vector<int> city_from(edges), city_to(edges);
 
    for(int i = 0; i < edges; i++)
        cin >> city_from[i] >> city_to[i];
 
    cout << hospital(city_nodes, city_from, city_to) << endl;
    return 0;
}
