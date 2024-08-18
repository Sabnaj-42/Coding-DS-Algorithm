#include<bits/stdc++.h>
using namespace std;
const int m=210000005;
long long ans[210000005];
int main()
{
    ans[0]=1;
    for(long long i=1;i<210000005;i++)
    {
        ans[i]=i+ans[i-1];
    }

    while(1)
    {
        long long n;cin>>n;
        if(n<0)break;
        else cout<<ans[n]<<endl;
    }
}
