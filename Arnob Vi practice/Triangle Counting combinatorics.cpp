#include<bits/stdc++.h>
using namespace std;
long long c[1000002];
long long s[1000002];
void solve()
{
    c[3]=0;
    s[3]=1;
    s[2]=0;
    for(int i=4;i<=1000000;i++)
    {
        long long d=i-2;
        s[i-1]=s[i-2]+(d/2);
        c[i]=c[i-1]+s[i-1];
    }
}
int main()
{
    solve();
    while(1)
    {
        long long n;cin>>n;
        if(n>=3)
        {
            cout<<c[n]<<endl;
        }
        else break;
    }
}
