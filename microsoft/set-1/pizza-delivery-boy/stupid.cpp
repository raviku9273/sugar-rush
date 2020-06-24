#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
/*************************** Template Begins ******************************/

/* ### READ-ONLY PART ### */
double pizzaDelivery(int input1, int input2, int** pts)
/* ### READ-ONLY PART ### */
{
    ll v = input1 ;
    ll n = input2 ;
    ll maxi = 0 ;
    fo(i , n)
    {
        fo(j , n)
        {
            ll x1 = pts[i][0] , y1 = pts[i][1] , x2 = pts[j][0] , y2 = pts[j][1] ;
            ll curr = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)) ;
            maxi = max(maxi , curr) ;
        }
    }
    long double ans = sqrtl(maxi) ;
    ans /= (v*1.0) ;
    ans = floor(ans*1000000 + 0.5) ;
    ans /= 1000000 ;
    return ans;
}

/*************************** Template Ends ******************************/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt" , "r" , stdin) ;
    freopen("outputf.txt" , "w" , stdout) ;
    freopen("error.txt" , "w" , stderr) ;
    #endif
    int input1, input2;
    
    int** input3;

    const int max_n = 1e3 + 3;
    input3 = (int**)malloc(max_n*sizeof(int*));

    for(int i = 0; i < max_n; i++)
        input3[i] = (int*)malloc(2*sizeof(int));

    scanf("%d %d", &input1, &input2);
    for(int i = 0; i < input2; i++)
    {
        scanf("%d %d", &input3[i][0], &input3[i][1]);
    }

    double res = pizzaDelivery(input1, input2, input3);
    printf("%lf\n", res);

    return 0;
}
