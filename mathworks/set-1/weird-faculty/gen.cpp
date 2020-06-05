/* Lavish Gupta */
#define ll long long
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#include<bits/stdc++.h>
using namespace std ;

int rand(int a, int b)
{
	return a + rand()%(b - a  + 1);
}

int main(int argc, char* argv[])
{
    srand(atoi(argv[1]));
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n = rand(1, (int)(1e5));

	cout << n << endl;
	
	for(int i = 0; i < n; i++)
		cout << rand(0, 1) << endl;

    return 0;
}
