#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
vector<int>g[N];
ll sum[N],cost[N],a[N];
ll ans=0;
void dfs1(int src,int par)
{
   sum[src]=a[src];
   for(int child:g[src])
   {
       if(child==par)continue;
           dfs1(child,src);
           sum[src]+=sum[child];
            cost[src]+=cost[child]+sum[child];
   }
}
void dfs2(int src,int par)
{
    ans=max(ans,cost[src]);
    for(int child:g[src])
    {
        if(child==par)continue;
        ll newcost=cost[src]-sum[child]-cost[child];
        cost[child]+=newcost-sum[child]+sum[src];
        sum[child]=sum[src];
        dfs2(child,src);
    }
}
int main()
{
   int n;cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<n;i++)
   {
       int a,b;cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
   }
   dfs1(1,-1);
   dfs2(1,-1);
   cout<<ans<<"\n";
}
