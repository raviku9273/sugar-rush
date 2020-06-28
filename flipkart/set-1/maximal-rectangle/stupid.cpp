#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define pub push_back
ll inf = 1e17 ;

void get_ans(ll arr[] , ll ans[] , ll m)
{
    //cout << "here" << endl ;
    ll left[m] , right[m] ;
    
    stack<ll> s ;
    fo(i , m)
    {
        ll u = arr[i] ;
        while(!s.empty())
        {
            ll ind = s.top() ;
            if(arr[ind] <= u)
                break ;
            right[ind] = i ;
            s.pop() ;
        }
        s.push(i) ;
    }
    while(!s.empty())
    {
        ll ind = s.top() ;
        right[ind] = m ;
        s.pop() ;
    }
    for(ll i = m-1 ; i >= 0 ; i--)
    {
        ll u = arr[i] ;
        while(!s.empty())
        {
            ll ind = s.top() ;
            if(arr[ind] <= u)
                break ;
            left[ind] = i ;
            s.pop() ;
        }
        s.push(i) ;
    }
    while(!s.empty())
    {
        ll ind = s.top() ;
        left[ind] = -1 ;
        s.pop() ;
    }
    fo(i , m)
    {
        ans[i] = (right[i] - left[i] - 1) ;
    }
    return ;
}

int maximal_rectangle(vector<vector<int>> &mat)
{
    ll n = mat.size() ;
    ll m = mat[0].size() ;

    ll dp[n][m] ;
    fo(j , m)
    {
        dp[0][j] = mat[0][j] ;
    }
    for(ll i = 1 ; i < n ; i++)
    {
        fo(j , m)
        {
            if(mat[i][j] == 0)
                dp[i][j] = 0 ;
            else
            {
                dp[i][j] = 1 + dp[i-1][j] ;
            }
        }
    }
    //cout << "complete" << endl ;
    //exit(0) ;
    ll ans_fin = 0 ;
    fo(i , n)
    {
        ll ans[m] ;
        get_ans(dp[i] , ans , m) ;
        
        fo(j , m)
        {
            ll curr = dp[i][j] * ans[j] ;
            ans_fin = max(ans_fin , curr) ;
        }
    }

    return ans_fin ;
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

    int row, col;

    cin >> row >> col;

    vector<vector<int>> mat(row, vector<int>(col, 0));

    for(auto &row_vec : mat)
        for(auto &ele : row_vec)
            cin >> ele;

    cout << maximal_rectangle(mat) << endl;
    return 0;
}
 
