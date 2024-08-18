#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>g[5005];
vector<int>siz(5005,0);
vector<bool>vi(5005,0);
ll res;
void pairr(vector<ll>v)
{
    ll total=0;
    for(int i=0;i<v.size();i++)total+=v[i];
    vector<ll>dp(total+1,0);
    dp[0]=1;
    for(int i=0;i<v.size();i++)
    {
        for(int j=total;j>=0;j--)
        {
            if(j-v[i]>=0)
            {
                if(dp[j-v[i]]==1)dp[j]=1;
            }
        }
    }
    ll sum=0;
    for(ll i=1;i<=total;i++)
    {
        if(dp[i]){sum=max(sum,(i*(total-i)));}
    }
    res+=sum;
}
void dfs(int from)//from node theke subtree fular size gula a vector a store kortechi
{
    vector<ll>a;
    siz[from]=1;
    vi[from]=1;
    for(auto to:g[from])
    {
        if(vi[to]==0)
        {
            dfs(to);
            siz[from]+=siz[to];//kono ekta node a jotogula subtree ache sobgula node er sum
        }
        a.push_back(siz[to]);
    }
    pairr(a);
}
int main()
{

   int n;cin>>n;
   for(int i=2;i<=n;i++)
   {
       int u;cin>>u;
       g[u].push_back(i);
       //g[i].push_back(u);
   }
   res=0;
   dfs(1);
   cout<<res<<"\n";
}
