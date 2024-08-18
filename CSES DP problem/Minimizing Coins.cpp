#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long inf=1e9;
ll dp[1000006];
int main()
{
    ll n,x;cin>>n>>x;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll j=0;j<=x;j++)dp [j]=inf;
   dp[0]=0ll;
    for(ll i=0;i<n;i++)
    {
        for(ll j=1;j<=x;j++)
        {
            if(a[i]<=j)
             dp[j]=min(dp[j],dp [j-a[i]]+1ll);
        }
    }
    if(dp[x]>=inf)cout<<-1<<"\n";
    else
    cout<<dp[x]<<"\n";
}
