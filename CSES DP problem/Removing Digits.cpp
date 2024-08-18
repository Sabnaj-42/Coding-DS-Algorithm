#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp(ll n)
{
    ll cnt=0;
    if(n==0)return 0;
    ll d=0;
    ll m=n;
    while(m>0)
    {
        d=max(d,m%10);
        m/=10;
    }
    return dp(n-d)+1;

}
int main()
{
    ll n;cin>>n;
    ll ans=dp(n);
    cout<<ans<<"\n";
}
