#include<bits/stdc++.h>
using namespace std;

int paths(string s, int n, int x, int y){
    
    int M=1000000007;
    int ans=0;
    int L=s.length();
    vector<pair<int,int>> p(L);
    
    int left=-1,right=-1;
    for(int i=L-1;i>=0;i--){
        if(s[i]=='l')left=i;
        else right=i;
        
        p[i]={left,right};
    }
    
    vector<unordered_map<int,int>> dp(L+1);// dp[i] : position, count
    dp[0][x]=1;
    if(x==y) ans=1;// empty subsequence
    
    for(int i=0;i<L;i++){
        for(auto it=dp[i].begin();it!=dp[i].end();++it){
            int position=it->first;
            int count=it->second;
            
            if(p[i].first != -1){
               int i2=p[i].first;
               int position2=position-1;
               
               if(position2>=0&&abs(position2-y)<=L-1-i2){
                   dp[i2+1][position2]=(dp[i2+1][position2]+count)%M;
                   if(position2==y)ans=(ans+count)%M;
               }
            }
            
            if(p[i].second != -1){
               int i2=p[i].second;
               int position2=position+1;
               
               if(position2<=n&&abs(position2-y)<=L-1-i2){
                   dp[i2+1][position2]=(dp[i2+1][position2]+count)%M;
                   if(position2==y)ans=(ans+count)%M;
               }
            }
        }
    }
    return ans;
}


int main(void){

	string str;
	cin >> str;

	int lim;
	cin >> lim;

	int start, finish;
	cin >> start >> finish;

	cout << paths(str, lim, start, finish) << endl;
    
    return 0;
}
