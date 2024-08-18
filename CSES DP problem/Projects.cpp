#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
     vector<pair<ll,ll>>e;
     ll n;cin>>n;
    ll s[n+1],p[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        ll d;cin>>d;
        e.push_back({d,i});
        cin>>p[i];
    }
    sort(e.begin(),e.end());
    vector<ll>ee;
    ee.push_back(0);
    for(int i=0;i<n;i++)ee.push_back(e[i].first);
    ll ans[n+1];
    int i=e[0].second;
    ans[1]=p[i];
    ans[0]=0;
    for(int i=1;i<n;i++)
    {
       ll index=e[i].second;
       ll d=s[index];
       ll f=lower_bound(ee.begin(),ee.end(),d)-ee.begin()-1;
       //cout<<f<<" ";
       ans[i+1]=max(ans[i],ans[f]+p[index]);
    }
    cout<<ans[n]<<"\n";
}
