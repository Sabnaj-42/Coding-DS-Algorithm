#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod=1e9+7;
ll dp[501][130000];
long long big_mod(long long a,long long b,long long m)//[(a^b)%m] here b is very large number almost 1e9
{
    if(b==0)return (1%mod);
    long long x=big_mod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)x=(x*a)%m;
    return x;
}
int main()
{
    ll n;cin>>n;
    ll a[n+1];
    ll d=(n*(n+1))/2;
    if(d%2){cout<<0<<"\n";return 0;}
    d/=2;
    for(ll i=1;i<=n;i++)a[i]=i;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=d;j++)
        {
            if(j==0){dp[i][j]=1;continue;}
            if(i==1)
            {
                if(j==a[i]){dp[i][j]=1;}
                continue;
            }
            if(a[i]>j)
            {
                dp[i][j]=dp[i-1][j]%mod;continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
            dp[i][j]%=mod;

        }
    }
   ll ans=dp[n][d];
   ll res=ans*big_mod(2ll,mod-2,mod);
   res%=mod;
   cout<<res<<"\n";
}
