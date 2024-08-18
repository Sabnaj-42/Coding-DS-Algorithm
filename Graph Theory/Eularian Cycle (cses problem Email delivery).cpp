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

const ll mod=1e9+7;
const ll inf=1e15;

ll big_mod(ll a,ll b, ll mod)
{
    if(b==0)return 1;
    ll x=big_mod(a,b/2,mod);
    x=(x*x)%mod;
    if(b%2)x=(x*a)%mod;
    return x;
}

using Matrix=vector<vector<ll>>;

vector<int>g[100005],edges[200005];
vector<int>degree(200005,0),mark(200005,0);
vector<int>path;

void dfs(int src)//sob edge ekbar kore visit kore abar source a fire asbe
{
  while(degree[src]<g[src].size())
  {
    int child=g[src][degree[src]];
    int edge=edges[src][degree[src]];//eta koto number edge
    degree[src]++;
    if(mark[edge])continue;//joid already ai edge visitied hoy tahole dorkar nai r visit er
    mark[edge]=1;
    dfs(child);
  }
  path.push_back(src);
}


int main()
{
  
  fast;
//Q
{
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int a,b;cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    
    // index all the edges
    edges[a].push_back(i);
    edges[b].push_back(i);
  }
  for(int i=1;i<=n;i++)//eular path er khetre src r destination er degree odd, bakigula sob even
  {
    if(g[i].size()%2){//eularian cycle er jonno sob node er degree even hote hoy
      cout<<"IMPOSSIBLE"<<endl;
      return 0;
    }
  }
  dfs(2);
  if(path.size()!=m+1)// // check if all nodes are connected.
  {
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }

  for(int i=0;i<path.size();i++)cout<<path[i]<<" ";
  cout<<endl;

  

}
return 0;
}