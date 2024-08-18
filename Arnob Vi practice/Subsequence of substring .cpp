#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<int>v[m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
          if(s[j]==t[i])
          {
              v[i].push_back(j);
          }
        }
    }
    long long ans=0;
    for(int l=0;l<n-m+1;l++)
    {
        int k=l-1,f=0;
        for(int j=0;j<m;j++)
        {
           vector<int>::iterator it;
           it=upper_bound(v[j].begin(),v[j].end(),k);
           if(it==v[j].end()){f=1;break;}
           k=v[j][it-v[j].begin()];
        }
        if(f==0)
        {
            //cout<<l<<" "<<k<<endl;
            ans+=(n-k);
        }
    }
    cout<<ans<<endl;
}
