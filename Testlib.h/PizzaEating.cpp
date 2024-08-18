#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b;cin>>a>>b;
    map<ll,ll>mb,ma;
    for(ll i=2;i*i<=b;i++)
    {
       if(b%i==0)
       {
           while(b%i==0)
           {
               b/=i;
               mb[i]++;
           }
       }
    }
    if(b>1)mb[b]++;
   for(ll i=2;i*i<=a;i++)
    {
       if(a%i==0)
       {
           while(a%i==0)
           {
               a/=i;
               ma[i]++;
           }
       }
    }
    if(a>1)ma[a]++;
    int f=0;
    for(auto x:ma)
    {
        if(x.second>mb[x.first]){f=1;break;}
        else{mb[x.first]=0;}
    }
    for(auto x:mb)
    {
        if(x.second>0){f=1;break;}
    }
    if(f==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
