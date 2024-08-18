#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int key[n+1],re[n+1];
    int c[n+1][n+1],p[n+1][n+1];
    for(int i=1;i<=n;i++)cin>>key[i];
    for(int i=1;i<=n;i++)cin>>re[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)p[i][j]=0;
    }
    for(int i=0;i<=n;i++)
    {
        c[i][i]=0;
        c[i][i+1]=re[i+1];
        p[i][i+1]=i+1;
    }
    int cnt=2;
    while(cnt<=n)
    {
        for(int i=0;i<=n;i++)
        {
            int j=i+cnt;
            if(j<=n)
            {
                int cost=INT_MAX;
                int index;
                int w=0;
                for(int m=i+1;m<=j;m++)w+=re[m];
                for(int k=i+1;k<=j;k++)
                {
                    int sum=c[i][k-1]+c[k][j];
                    if(sum<cost)
                    {
                        cost=sum;
                        index=k;
                    }
                }
                c[i][j]=cost+w;
                p[i][j]=index;
            }
            else break;
        }
        cnt++;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)cout<<p[i][j]<<" ";
        cout<<endl;
    }
}
