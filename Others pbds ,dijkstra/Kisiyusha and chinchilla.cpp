#include<bits/stdc++.h>
using namespace std;
#define N 200005
vector<pair<int,int>>g[N];
vector<int>ans;
int dfs(int src,int p)
{
    int total=1;
    for(auto [next,num]:g[src])
    {
        if(next!=p)
        {
            int cnt=dfs(next,src);
            if(cnt==0){ans.push_back(num);}
            total+=cnt;
        }
    }
    if(total==3){return 0;}
    else return total;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
       int n;cin>>n;
       for(int i=0;i<=n;i++)g[i].clear();
       ans.clear();
       for(int i=1;i<n;i++)
       {
           int u,v;
           cin>>u>>v;
           g[u].push_back({v,i});
           g[v].push_back({u,i});
       }
       int x=dfs(1,-1);
       if(x)
       {
           cout<<-1<<"\n";continue;
       }
       cout<<ans.size()<<"\n";
       //if(ans.size()==0)continue;
       for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
       cout<<"\n";
    }
}
