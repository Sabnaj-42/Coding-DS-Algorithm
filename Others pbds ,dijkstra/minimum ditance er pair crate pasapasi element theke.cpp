#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;cin>>n>>m;
    vector<ll>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    if((n*(n-1))/2<m)
    {
        cout<<"no\n";
        return 0;
    }
    sort(b.begin(),b.end());
    set<pair<ll,pair<ll,ll>>>s;
    for(int i=1;i<n;i++)
    {
        s.insert({a[i]-a[i-1],{i-1,i}});
    }
    for(ll x:b)
    {
        auto it=*s.begin();
        if(it.first>x)
        {
            cout<<"no\n";
            return 0;
        }
        int i=it.second.first;
        int j=it.second.second;
        s.erase(s.begin());
        if(i>0)
        {
            s.insert({a[j]-a[i-1],{i-1,j}});
        }
        if(j<n-1)
        {
            s.insert({a[j+1]-a[i],{i,j+1}});
        }
        if(i>0&&j<n-1)
        {
            s.insert({a[j+1]-a[i-1],{i-1,j+1}});
        }

    }
    cout<<"yes\n";
    return 0;
}
