#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int v[1000106];
vector<int>graph[1000106];
int f=0;
void dfs(int src)
{
    v[src]=1;
    for(int i=0;i<graph[src].size();i++)
    {
        int next=graph[src][i];
        if(v[next]==0)dfs(next);
        else if(v[next]==1)//Cycle found
            {f=1;return ;}
    }
    ans.push_back(src);
    v[src]=2;
}

int main()
{
    int  n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1; i<=n; i++)
        {
            if(v[i]==0)dfs(i);
        }
        reverse(ans.begin(),ans.end());
    if(f==1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(int i=0; i<ans.size(); i++)cout<<ans[i]<<endl;

    }


}
