#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod=1e9+7;
ll dp[1000006];
ll a[105];
ll recursion(ll x, ll n)
{
    //cout<<x<<" ";
   if(x==0){return 1;}
   if(x<0)return 0;
   if(dp[x]!=-1){return dp[x];}
   dp[x]=0;
   for(int i=0;i<n;i++)
   {
       (dp[x]+=recursion(x-a[i],n)%mod)%mod;
   }
   return dp[x]%mod;
}
int main()
{
    ll n,x;
    cin>>n>>x;
    for(int i=0;i<=x;i++)dp[i]=-1;
    for(ll i=0;i<n;i++)cin>>a[i];
    ll ans=recursion(x,n);
    cout<<max(0ll,ans)<<"\n";

}
