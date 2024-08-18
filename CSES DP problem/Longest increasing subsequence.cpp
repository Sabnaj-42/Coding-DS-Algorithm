#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;cin>>n;
    vector<ll>v;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    v.push_back(0);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
       ll d=a[i];
       auto it=lower_bound(v.begin(),v.end(),d);
       if(it==v.end())
       {
           ans++;
           v.push_back(d);continue;
       }
       int index=it-v.begin();
       v[index]=a[i];

    }
    cout<<ans<<"\n";
}
