#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,c;
};
ll dist[100005];
ll inf=1000007;
ll to;
ll n,m;//n= total node,m=total edge
struct node graph[100010];
void bellman(int src)
{
    for(int i=1;i<=n;i++)dist[i]=inf;
   dist[src]=0;
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
          if(dist[graph[j].a]<inf)
          {
              dist[graph[j].b]=min(dist[graph[j].b],dist[graph[j].a]+graph[j].c);
          }
       }
   }
   cout<<dist[to];
}
int main()
{
    cin>>n>>m>>to;
    for(int i=0;i<m;i++)
    {
        cin>>graph[i].a>>graph[i].b>>graph[i].c;
    }
    bellman(1);


}
