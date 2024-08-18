#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod=1e9+7;
ll dp[1000006];
int main()
{
    ll n,x;cin>>n>>x;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
   dp[0]=1ll;
    for(ll i=0;i<n;i++)
    {
        for(ll j=1;j<=x;j++)
        {
            if(a[i]<=j)
             dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    cout<<dp[x]<<"\n";
}

