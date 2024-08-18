#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        long long a,b,ans=1;
        cin>>a>>b;a--;b--;
        int c=a-b;
        for(int i=c+1;i<=a;i++)ans*=i;
        for(int i=1;i<=b;i++)ans/=i;
        cout<<ans<<endl;
    }
}
