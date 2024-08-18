#include<bits/stdc++.h>
#define inf 1000000
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    int d[n+1][n+1];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(i==j)d[i][j]=0;
            else d[i][j]==inf;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=c;
        d[b][a]=c;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(d[i][k]!=inf&&d[k][j]!=inf)
                {
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<"Distance from "<<i<<" to"<<j<<" :  "<<d[i][j]<<endl;
    }
}
