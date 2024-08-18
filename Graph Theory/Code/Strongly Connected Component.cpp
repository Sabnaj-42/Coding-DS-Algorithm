#include<bits/stdc++.h>
using namespace std;
bool visit[1001],onstack[1001];
vector<int>graph[1001];
int in[1001],low[1001];
stack<int>st;
int timer=1,scc=0;
void dfs_scc(int node)
{
    visit[node]=1;
    onstack[node]=1;
    in[node]=low[node]=timer;timer++;
    st.push(node);
    for(int child:graph[node])
    {
        if(visit[child]==1&&onstack[child]==1)
        {
            low[node]=min(low[node],child[in]);
        }
        else if(visit[child]==0)
        {
            dfs_scc(child);
            if(onstack[child]==1)
            {
                low[node]=min(low[node],low[child]);
            }
        }
    }
    if(in[node]==low[node])
    {
        scc++;
        cout<<"SCC : "<<scc<<endl;
        while(1)
        {
            int u=st.top();
            st.pop();
            onstack[u]=0;
            cout<<u<<" ";
            if(u==node)break;
        }
        cout<<endl;
    }
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++)visit[i]=0,onstack[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)dfs_scc(i);
    }
}
