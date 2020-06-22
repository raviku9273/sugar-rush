#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pub push_back
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
ll n , c = 0;
/*********************** Template Begins ****************************/
 
void DFS(vector<pair<ll ,ll> > adj[] , ll vis[] , ll comp[] , ll weight , ll u)
{
    vis[u] = 1 ;
    comp[u] = c ;
    fo(i , adj[u].size())
    {
        ll v = adj[u][i].first ;
        ll w = adj[u][i].second ;
        if(vis[v] == 0 && w == weight)
        {
            DFS(adj , vis , comp , weight , v) ;
        }
    }
    return ;
}
 
ll get_ans(vector<pair<ll, ll> > adj[] , ll weight)
{
    c = 0 ;
    ll vis[n] , comp[n] ;
    fo(i , n)
        vis[i] = comp[i] = 0 ;
    fo(i , n)
    {
        if(vis[i] == 0)
        {
            c++ ;
            DFS(adj , vis , comp , weight , i) ;
        }
    }
    ll maxi = 0 ;
    vector<ll> check[c+1] ;
    fo(i , n)
    {
        check[comp[i]].pub(i+1) ;
        maxi = max((ll)maxi , (ll)check[comp[i]].size()) ;
    }  
    ll curr = 0 ;
    if(maxi <= 1)
        return 0 ;  
    for(ll i = 1 ; i <= c ; i++)
    {
        if(check[i].size() < maxi)
            continue ;
        curr = max(curr , check[i][check[i].size()-1] * check[i][check[i].size()-2]) ;
    }
    return curr ;
}
 
 
int countCandies(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight)
{
    n = friends_nodes ;
    vector<pair<ll ,ll> > adj[n] ;
    fo(i , friends_from.size())
    {
        ll u = friends_from[i] ;
        ll v = friends_to[i] ;
        u-- ; v-- ;
        ll w = friends_weight[i] ;
        adj[u].pub(mp(v , w)) ;
        adj[v].pub(mp(u , w)) ;
    }
 
    ll ans = 0 ;
    for(ll i = 1 ; i <= 100 ; i++)
    {
        ans = max(ans , get_ans(adj , i)) ;
    }
    return ans ;
 
}
 
/*********************** Template Ends ****************************/
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int friends_nodes;
    cin >> friends_nodes;
 
 
    int dim;
    cin >> dim;
 
    vector<int> friends_from(dim);
    for(auto &ele : friends_from)
        cin >> ele;
 
    cin >> dim;
    vector<int> friends_to(dim);
    for(auto &ele : friends_to)
        cin >> ele;
 
    cin >> dim;
    vector<int> friends_weight(dim);
    for(auto &ele : friends_weight)
        cin >> ele;
 
    cout << countCandies(friends_nodes, friends_from, friends_to, friends_weight);
    cout << endl;
    return 0;
}
