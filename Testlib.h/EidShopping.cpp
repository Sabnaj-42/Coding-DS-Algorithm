
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,q,s=0;
    cin>>n>>q;
    ll v[n][n];
    ll sum[n+1][n+1];
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)cin>>v[i][j];
    }
    // prefix sum of 2 D array
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
          sum[i+1][j+1]=0;
          if(i!=0)sum[i+1][j+1]+=sum[i][j+1];
          if(j!=0)sum[i+1][j+1]+=sum[i+1][j];
          if(i!=0&&j!=0)sum[i+1][j+1]-=sum[i][j];
          sum[i+1][j+1]+=v[i][j];
      }
    }
    ll ans=0;
    while(q--)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ans+=sum[x2][y2];
        if(x1!=1)ans-=sum[x1-1][y2];
        if(y1!=1)ans-=sum[x2][y1-1];
        if(x1!=1&&y1!=1)ans+=sum[x1-1][y1-1];
       // cout<<ans<<endl;

    }
    cout<<ans<<"\n";


}
