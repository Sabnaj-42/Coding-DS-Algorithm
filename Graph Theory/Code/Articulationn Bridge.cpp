#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
int in[1001],low[1001],visit[1001];
int timer=0;
void dfs_Bridge(int node,int par)
{
    visit[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(int child:graph[node])
    {
        if(child==par)continue;
        if(visit[child]==1)//Back edge (node-child edge is a back edge)
        {
            low[node]=min(low[node],in[child]);
        }

        else
        {
            //node - child edge is a froward edge
            dfs_Bridge(child,node);
            if(low[child]>in[node])
            {
                cout<<node<<" - "<<child<<" is a bridge"<<endl;
            }
            low[node]=min(low[child],low[node]);
        }
    }
}
int main()
{
    int n;cin>>n;
    int m;cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);

    }
    dfs_Bridge(1,-1);//root node er parent -1 kore dilam
}
