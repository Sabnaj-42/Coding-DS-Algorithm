#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ncr(ll n,ll r)
{
    if(r==0)
    {
        return 1;
    }

    return ncr(n,r-1)*(n-r+1)/r;
}

int main()
{
    ll n,r;
    cin>>n>>r;
    cout<<ncr(n,r)<<endl;
}
