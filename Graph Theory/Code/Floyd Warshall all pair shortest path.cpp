#include<bits/stdc++.h>
using namespace std;
int inf=10000000;

int main()
{
    int n,m;cin>>n>>m;
    int dist[n+1][n+1];
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(i==j)dist[i][j]=0;
           else dist[i][j]=inf;
       }
   }
   for(int i=0;i<m;i++)
   {
       int a,b,c;
       cin>>a>>b>>c;
       dist[a][b]=c;
   }
   for(int k=1;k<=n;k++)
   {
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
               if(dist[i][k]!=inf&&dist[k][j]!=inf)
               {
                   dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
               }
           }
       }
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(dist[i][j]!=inf)cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
       }
   }
}
