/* Lavish Gupta */
#define ll long long
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#include<bits/stdc++.h>
using namespace std ;

int rand(int a, int b)
{
	return a + rand()%(b - a  + 1);
}

void solve()
{
    
    ll n , thrones ;
    /* cin >> n >> thrones ; */
    n = rand(1, 500);
    thrones = rand(0, n*n);
    ll cnt = 0 ;
    ll arr[n][n] ;
    fo(i , n)
    {
        fo(j , n)
        {
            ll val = rand() ;
            if(cnt < thrones)
            {
                val = (abs(val) % 3) ;
                val-- ;
                if(val == -1)
                {
                    ll a = rand() ;
                    a = abs(a)%2 ;
                    if(a != 0)
                    {
                        ll b = rand() ;
                        b = abs(b)%2 ;
                        val = b ;
                    }

                }
                arr[i][j] = val ;
                if(val == -1)
                    cnt++ ;
            }
            else
            {
                val = (abs(val)%2) ;
                arr[i][j] = val ;
            }
        }
    }
    arr[0][0] = abs(arr[0][0]) ;
    arr[n-1][n-1] = abs(arr[n-1][n-1]) ;
    cout << n << '\n' ;
    fo(i , n)
    {
        fo(j , n)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n' ;
    }
    return ;
}

int main(int argc, char* argv[])
{
    srand(atoi(argv[1]));
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
        ll t ;
    //cin >> t ;
    t = 1 ;
    
    //cout << t << endl ;
    while(t--)
    {
        //cout << "aaa" << endl ;
        solve() ;
    }
    return 0;
}
