#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=1;
    map<char,int>mp;
    //cin>>t;

           string s;
           cin>>s;
           int n=s.length();
           int cnt=0;
           int ans=0;
           for(int i=0;i<n;i++)
           {
              // cout<<i<<endl;
               mp[s[i]]++;
               if(mp[s[i]]>=2)
               {
                   mp.clear();
                  ans=max(ans,cnt);
                  cnt=0;
                  for(int j=i-1;j>=0;j--)
                  {
                      if(s[j]==s[i])
                      {
                          i=j+1;
                          break;
                      }
                  }
               }
               else
               {
                   cnt++;
               }
           }
           ans=max(ans,cnt);
           cout<<ans<<endl;

}
