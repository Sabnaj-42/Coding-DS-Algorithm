#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,q,s=0;
    cin>>n>>q;
    ll v[n+1][n+1];
    ll sum[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=n;j++)cin>>v[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        sum[i][0]=0;
      for(int j=1;j<=n;j++)
      {
         sum[i][j]=sum[i][j-1]+v[i][j];
      }
    }
    ll ans=0;
    while(q--)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<=x2;i++)
        {
            ans+=(sum[i][y2]-sum[i][y1-1]);
        }

    }
    cout<<ans<<"\n";


}
