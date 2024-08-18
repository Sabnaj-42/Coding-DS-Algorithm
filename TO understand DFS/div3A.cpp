#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
ll b[200005];
ll ans[200006];
ll need[200005];
ll have[200005];
ll ans1[200005];
bool visit[200005];
ll top;
void push(ll data)
{
    ans[top]=data;
    top++;
}
vector<ll>graph[200005];
void dfs(ll src,ll par)
{
    visit[src]=1;
    if(src!=1)
    {need[src]=need[par]+b[src];
    push(need[src]);
    have[src]=have[par]+a[src];}
    for(ll i=0;i<graph[src].size();i++)
    {
        ll child=graph[src][i];
        if(visit[child]==0)dfs(child,src);
    }
    if(src!=1)
        {
            ll r=upper_bound(ans,ans+top,have[src])-ans;
            ans1[src]=max((ll)0,r);
            top--;
        }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        top=0;

        for(ll i=1;i<200005;i++){graph[i].clear();visit[i]=0;}

        ll n;cin>>n;
        ll p,aa,bb;
        for(ll i=2;i<=n;i++)
        {
            cin>>p>>aa>>bb;
            graph[p].push_back(i);
            graph[i].push_back(p);
            a[i]=aa;
            b[i]=bb;
        }
        dfs(1,-1);
        for(ll i=2;i<=n;i++)cout<<ans1[i]<<" ";
        cout<<endl;

    }
}
