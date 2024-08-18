#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
int visit[1001],in[1001],low[1001];
int timer=0;
set<int>s;
void dfs_art_point(int node,int parent)
{
    visit[node]=1;
    int children=0;
    in[node]=low[node]=timer;
    timer++;
    for(int child:graph[node])
    {
        if(child==parent)continue;
        if(visit[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs_art_point(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in[node]&&parent!=-1)
            {
                s.insert(node);
            }
            children++;
        }
    }
    if(parent==-1&&children>1)s.insert(node);
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs_art_point(1,-1);
    for(auto it:s)
    {
        cout<<it<<" ";
    }

}
