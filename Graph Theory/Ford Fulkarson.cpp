#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m;
    cin>>n>>m;
    int s,t;cin>>s>>t;
     vector<int>g[n+1];
    int c[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)c[i][j]=0;
    }
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        c[u][v]=w;
    }
    int maxFlow=0;
    while(1)
    {
        int visit[n+1];
        for(int i=1;i<=n;i++)visit[i]=0;
        queue<int>q;
        q.push(s);
        int p[n+1];
        while(!q.empty())
        {
           int from=q.front();
           visit[from]=1;
           q.pop();
           for(int i=0;i<g[from].size();i++)
           {
               int to=g[from][i];
               if(visit[to]==0&&c[from][to]>0)
               {
                   q.push(to);
                   p[to]=from;
               }
           }
        }
        if(visit[t]==0)break;
        int i=t;
        int mn=INT_MAX;
        while(1)
        {
            if(i==s)break;
            int j=p[i];
            mn=min(mn,c[j][i]);
            i=p[i];
        }
        cout<<mn<<" ";
        maxFlow+=mn;
         i=t;
        while(1)
        {
            if(i==s)break;
            int j=p[i];
            c[j][i]-=mn;
            c[i][j]+=mn;
            i=p[i];
        }
    }
    cout<<endl;
    cout<<maxFlow<<endl;
}
