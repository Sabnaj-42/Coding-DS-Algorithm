
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin>>n>>w;
    int a[n];
    for(int i=1; i<=n; i++)cin>>a[i];
    int sum[n+1][w+1];
    for(int i=0; i<=n; i++)sum[i][0]=1;
    for(int i=1; i<=w; i++)
    {
      sum[0][i]=0;

    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(sum[i-1][j]==1)sum[i][j]=1;
            else if(a[i]>j)sum[i][j]=0;
            else
            {
                sum[i][j]=sum[i-1][j-a[i]];
            }
        }
    }
    if(sum[n][w]==1)
    {
        cout<<"YES"<<endl;
        int j=w;
        for(int i=n;i>0;i--)
        {
            if(sum[i-1][j]==1)continue;
            else
            {
                cout<<a[i]<<" ";
                j-=a[i];
            }
        }
        cout<<endl;

    }
    else cout<<"NO"<<endl;


}
