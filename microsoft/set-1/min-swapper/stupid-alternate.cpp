#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	while(s!="0")
	{
		int a[26]={0};
		for(int i=0;i<s.size();i++)
			a[s[i]-'a']++;
		int j=0;
		for(int i=0;i<26;i++)
			if(a[i]%2)
				j++;
		if(j>1)
			cout<<"Impossible\n";
		else
		{
			int i=0,l,r;
			j=s.size()-1;
			int ans=0;
			while(i<j)
			{
				if(s[i]!=s[j])
				{
					for(l=i+1;l<j;l++)
						if(s[l]==s[j])
							break;
					for(r=j-1;r>i;r--)
						if(s[r]==s[i])
							break;
					if((l-i)<(j-r))
					{
						ans+=(l-i);
						for(;l>i;l--)
							s[l]=s[l-1];
						s[i]=s[j];
					}
					else
					{
						ans+=(j-r);
						for(;r<j;r++)
							s[r]=s[r+1];
						s[j]=s[i];
					}
				}
				i++;
				j--;
			}
			cout<<ans<<"\n";
		}
		cin>>s;
	}
	return 0;
}
