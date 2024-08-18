#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,m;cin>>n>>m;
    ll a[m];
    for(int i=0;i<m;i++)cin>>a[i];
    ll d=*min_element(a,a+m);
    ll t=ceil(n/(double)d);
    if(t%2==1)cout<<2<<"\n";
    else cout<<1<<"\n";

}
