#include<bits/stdc++.h>
using namespace std;
static long long mod=1e9+7;
long long big_mod(long long a,long long b,long long m)//[(a^b)%m] here b is very large number almost 1e9
{
    if(b==0)return (1%m);
    long long x=big_mod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)x=(x*a)%m;
    return x;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<big_mod(a,b,mod);
}
//Farmats little theorem
//(a^(-1))%mod=(a^(mod-2))%mod
