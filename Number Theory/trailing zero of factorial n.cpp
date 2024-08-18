//trailing zero(last a kotogula zero ache) of n!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll trailingZero(ll n)
{
    ll zero=0;
    for(ll i=5;i<=n;i*=5)
    {
        zero+=(n/i);
    }
    return zero;
}
int main()
{

    ll n;cin>>n;
    ll ans=trailingZero(n);
    cout<<ans<<endl;
}
