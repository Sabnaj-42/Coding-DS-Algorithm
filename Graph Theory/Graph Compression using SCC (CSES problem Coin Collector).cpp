#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
#define ll long long

#define PB push_back
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define Q int tt; cin>>tt ; for(int qq=1; qq <= tt; qq++)
#define endl "\n"
 
//PBDS start
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>//sudhu less dile uniqe element rakhbe ,,less_equal dile duplicate value rakhbe
new_data_set;
//PBDS end
 
 
//Debug start
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
//Debug End

struct SCC{
  vector<ll>g[100005],g1[100005];
  vector<bool>vis;
  vector<ll>comp,comps;
  stack<ll>s;
  void init(int n)
  {
    vis.resize(n+1,0);comp.resize(n+1,0);
  }

  void dfs(int src)//top sort
  {
    vis[src]=1;
    for(auto child:g[src])
    {
      if(vis[child])continue;
      dfs(child);
    }
    s.push(src);
  }

  void reverse(int src,int col)//scc determine
  {
    comp[src]=col;
    for(auto child:g1[src])
    {
      if(comp[child]!=0)continue;
      reverse(child,col);
    }
  }

  void generate(int n)
  {
    init(n);
    for(int i=1;i<=n;i++)
    {
      if(vis[i])continue;
        dfs(i);
    }

    
    while(!s.empty())
    {
      int src=s.top();
      s.pop();
      if(comp[src]!=0)continue;
      reverse(src,src);
      comps.push_back(src);
    }
  }

}scc;

vector<ll>rg[100005],group(100005,0);
ll dp[100005];



int main()
{
  
  fast;
//Q
{
  int n,m;cin>>n>>m;
  vector<ll>c(n+1);
  for(int i=1;i<=n;i++)cin>>c[i];
  for(int i=0;i<m;i++)
  {
    int a,b;cin>>a>>b;
    scc.g[a].push_back(b);
    scc.g1[b].push_back(a);
  }

  scc.generate(n);
  //dbg("sabnaj");
  //dbg(scc.comps);
  for(int i=1;i<=n;i++)
  {
    group[scc.comp[i]]+=c[i];
    for(auto j:scc.g[i])
    {
      if(scc.comp[i]!=scc.comp[j])
      {
         rg[scc.comp[j]].push_back(scc.comp[i]);
      }
    }
  }
  //dbg("sabnaj");
  ll ans=0;
  for(ll i:scc.comps)
  {
    if(dp[i]!=0)continue;
    dp[i]=group[i];
    //dbg(group[i]);
    for(auto j:rg[i])
    {
      dp[i]=max(dp[i],dp[j]+group[i]);
    }
    ans=max(ans,dp[i]);
  }
  cout<<ans<<endl;
}
return 0;
}
