#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
struct node
{
    int a,b,cost;
};
int main()
{
    int n,m;cin>>n>>m;
     node graph [m];
    for(int i=0;i<m;i++)
    {
        cin>>graph[i].a>>graph[i].b>>graph[i].cost;
    }
    int dist[n+1];
    for(int i=0;i<=n;i++)dist[i]=inf;
    int src;cin>>src;
    dist[src]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[graph[j].a]<inf)
            {
                dist[graph[j].b]=min(dist[graph[j].b],dist[graph[j].a]+graph[j].cost);
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";

}
