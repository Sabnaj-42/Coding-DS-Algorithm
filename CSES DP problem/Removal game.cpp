#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
const long long mx=5005;
long long dp[mx][mx][2];
long long a[mx];
long long solve(ll i,ll j,ll f)
{
    if(i>j)return 0;
    if(i==j)
    {
        if(f==1)
         return a[i];
         return 0;
    }
    if(dp[i][j][f]!=inf)return dp[i][j][f];
    ll ans=0;
   if(f==1)
   {
       ans=a[i]+solve(i+1,j,0);
       ans=max(ans,a[j]+solve(i,j-1,0));
   }
   else
   {
      ll temp1=a[i]+solve(i+1,j,0);
      ll temp2=a[j]+solve(i,j-1,0);
      if(temp1>temp2)
        return dp[i][j][f]=solve(i+1,j,1);
    return dp[i][j][f]=solve(i,j-1,1);
   }
   dp[i][j][f]=ans;
   return ans;

}

int main()
{
   for(int i=0;i<mx;i++)
   {
       for(int j=0;j<mx;j++)
        dp[i][j][0]=inf,dp[i][j][1]=inf;
   }
   ll n;cin>>n;
   for(int i=0;i<n;i++)cin>>a[i];
   ll ans=solve(0ll,n-1,1);
   cout<<ans<<"\n";
}
