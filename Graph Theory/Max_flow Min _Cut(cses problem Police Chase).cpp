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

int main()
{
  
  fast;
//Q
{
 
  ll n,m;cin>>n>>m;
  vector<ll>g[n+1];
  vector<vector<ll>>c(n+1,vector<ll>(n+1,0));
  for(int i=0;i<m;i++)
  {
    ll a,b;cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    c[a][b]++;//multiple path possible between two edge
    c[b][a]++;
  }

  while(1)
  {
    queue<ll>q;
    q.push(1);
    vector<int>vi(n+1,0),p(n+1,0);
    vi[1]=1;
    //dbg(1);
    while(!q.empty())//finding augmented path
    {
      int from=q.front();
      q.pop();
      //dbg(from);
      for(auto child:g[from])
      {
        int to=child;
        if(vi[to]==0 && c[from][to]>0)
        {
          q.push(to);
          p[to]=from;
          vi[to]=1;
        }
      }
    }

    if(vi[n]==0)break;

    int to=n;
    ll mn=1e15;
    while(to!=1)//finding minimum cost value in augmented path
    {
      int from=p[to];
      mn=min(mn,c[from][to]);
      to=from;
    }

    to=n;
    while(to!=1)//subtracting minimum cost from edge, and adding cost in reverse edge
    {
      ll from=p[to];
      c[from][to]-=mn;
      c[to][from]+=mn;
      to=from;

    }
  }
  
  //using the changed edge in max_flow , detecting min_cut edge

  vector<pair<int,int>>ans;
  queue<int>q;
  q.push(1);
  vector<int>vis(n+1,0);
  vis[1]=1;
  while(!q.empty())
  {
    int from=q.front();
    q.pop();

    for(auto child:g[from])
    {
      if(vis[child]==0 && c[from][child]>0)
      {
        q.push(child);
        vis[child]=1;
      }

    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int child:g[i])
    {
      if(child<=i)continue;
      if(vis[i]!=vis[child])
      {
        if(c[i][child]<0)continue;
        ans.push_back({i,child});
        c[i][child]=-1;
      }
    }
  }

  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  }
}
return 0;
}