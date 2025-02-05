#include<bits/stdc++.h>
using namespace std;
int pr[1001][24];
int lv[1001];
vector<int>g[1001];
void dfs(int u,int pp)
{
    pr[u][0]=pp;
    for(int v:g[u])
    {
        if(v==pp)continue;
        lv[v]=lv[u]+1;
        dfs(v,u);
    }
}
void init(int n)
{
    for(int j=1;j<=23;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(pr[i][j-1]==-1)continue;
            pr[i][j]=pr[pr[i][j-1]][j-1];
        }
    }
}
int lca(int x,int y)
{
    if(lv[x]<lv[y])swap(x,y);
    for(int i=22;i>=0;i--)
    {
        if(lv[x]-(1<<i)>=lv[y])x=pr[x][i];
    }
    if(x==y)return x;
    for(int i=22;i>=0;i--)
    {
        if(pr[x][i]!=-1&&pr[x][i]!=pr[y][i])
        {
            x=pr[x][i];y=pr[y][i];
        }
    }
    return pr[x][0];
}

int main()
{
    int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<=22;j++)pr[i][j]=-1;
    }
    dfs(1,-1);
    init(n);
   cout<<lca(9,7);
}
