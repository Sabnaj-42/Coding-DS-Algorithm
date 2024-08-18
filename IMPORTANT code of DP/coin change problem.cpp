#include<bits/stdc++.h>
using namespace std;
long long ans[55][255];
int main()
{
    long long n,m;
    cin>>n>>m;
    long long a[m+1];
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=0;i<=m;i++)ans[i][0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<a[i])ans[i][j]=ans[i-1][j];
            else
            ans[i][j]=ans[i-1][j]+ans[i][j-a[i]];
        }
    }
    cout<<ans[m][n]<<endl;
}
