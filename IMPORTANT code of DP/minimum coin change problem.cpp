#include<bits/stdc++.h>
using namespace std;
long long ans[10001][10001];
int main()
{
    long long n,s;cin>>n>>s;
    long long a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<=n;i++)ans[i][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=s;j++)ans[i][j]=INT_MAX;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(a[i]>j)ans[i][j]=ans[i-1][j];
            else
                ans[i][j]=min(ans[i-1][j],ans[i][j-a[i]]+1);
        }
    }
    if(ans[n][s]>s)cout<<-1<<endl;
    else cout<<ans[n][s]<<endl;

}
