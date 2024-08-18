#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   ll n,x;cin>>n>>x;
   vector<ll>a,b;
   for(int i=0;i<n/2;i++)
   {
       ll k;cin>>k;
       a.push_back(k);
   }
   for(int i=n/2;i<n;i++)
   {
       ll k;cin>>k;
       b.push_back(k);
   }
   unordered_map<ll,ll>mp;
   ll y=n/2;
   ll mx=(1<<y)-1;
   for(ll i=1;i<=mx;i++)
   {
       ll d=i;
       ll index=0;
       ll s=0;
       while(d>0)
       {
           if(d&1)s+=a[index];
           index++;
           d=d>>1;
       }
       mp[s]++;
   }
   ll ans=0;
   mx=(1<<(n-y))-1;
   ans+=mp[x];
   for(ll i=1;i<=mx;i++)
   {
       ll d=i;
       ll index=0;
       ll s=0;
       while(d>0)
       {
           if(d&1)s+=b[index];
           index++;
        d=d>>1;
       }
       if(s<=x)
       {
           if(s==x)ans++;
           else ans+=(mp[x-s]);
       }
   }
   cout<<ans<<"\n";
}
