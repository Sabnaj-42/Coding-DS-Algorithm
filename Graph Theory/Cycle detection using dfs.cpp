#include<bits/stdc++.h>
using namespace std;
//#define ll long long
int f=0;
int v[200005];
vector<int>g[200005];
void dfs(int src,int p)
{
    v[src]=1;
    for(int j=0;j<g[src].size();j++)
    {
        int next=g[src][j];
        if(v[next]==0)
        {
           dfs(next,src) ;
        }
        else if(v[next]==1)
        {
            if(next!=p&&p!=-1)//detected a cycle
            {
                f=1;
                //cout<<next<<" "<<p<<"\n";
            }
        }
    }
    v[src]=2;
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;cin>>n;
      for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)
        {
            int a;cin>>a;
            g[a].push_back(i);
            g[i].push_back(a);
        }
        int gg=0;
        int mn=0,mx=0;
        for(int i=1;i<=n;i++)v[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0)
            {

                mx++;f=0;
                dfs(i,-1);
                if(f==0)gg=1;
                else mn++;
            }
        }
        if(gg==1)mn++;
        cout<<mn<<" "<<mx<<"\n";
    }

}
