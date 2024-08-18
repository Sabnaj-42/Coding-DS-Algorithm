#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100005];
const long long mod=1e9+7;
ll dp[101][100005];
ll dpf(ll i,ll e,ll m,ll n)
{
    //cout<<e<<" "<<i<<"\n";
     if(e>m || e<1)return 0;
    if(i==n)
    {
        if(a[i]==0)
        {
            ll x=0;
            if(((e+1)>=1&&e+1<=m)&&(e-1>=1&&(e-1)<=m))x= 2;
            else if(((e+1)>=1&&e+1<=m)||(e-1>=1&&(e-1)<=m)) x= 1;
           if(e>=1&&e<=m)x++;
           return x;
        }
        if(abs(e-a[i])>1)return 0;
        return 1;
    }
    if(dp[e][i]!=-1)return dp[e][i];
    if(a[i]!=0)
    {
        if(abs(e-a[i])>1)return 0;
        return dp[e][i]=dpf( i+1, a[i], m, n);
    }
   // cout<<dp[e][i]<<" ";
    return dp[e][i]=(dpf( i+1, e+1, m, n)+dpf( i+1, e-1, m, n)+dpf( i+1, e, m, n))%mod;
}
int main()
{
   ll n,m;cin>>n>>m;
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=0;i<=m;i++)
   for(int j=0;j<=n;j++)
    dp[i][j]=-1;
   if(n==1)
   {
       if(a[1]==0)cout<<m<<"\n";
       else cout<<1<<"\n";
       return 0;
   }
   if(a[1]==0)
   {
       ll ans=0;
       for(ll j=1;j<=m;j++)
       {
          ans+=dpf(2,j,m,n);
          ans%=mod;
       }
       cout<<ans<<"\n";
       return 0;
   }
   ll ans=dpf(2,a[1],m,n);
   cout<<ans<<"\n";

}
