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
vector<int>g[200005],g1[200005],vis(200005,0),col(200005,0);
stack<int>s;
void dfs(int src)
{
  vis[src]=1;
  for(auto child:g[src])
  {
    if(vis[child])continue;
    dfs(child);
  }
  s.push(src);
}

void reverse(int src,int cnt)
{
  col[src]=cnt;
  vis[src]=1;
  for(auto child:g1[src])
  {
    if(vis[child])continue;
    reverse(child,cnt);
  }
}

int main()
{
  
  fast;
//Q
{
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    int a,b,d1,d2;
    char c1,c2;
    cin>>c1>>a>>c2>>b;
    (c1=='+')?d1=1:d1=0;
    (c2=='+')?d2=1:d2=0;
    g[(1-d1)*m+a].push_back((d2*m)+b);//converting boolean logic into graph
    g1[(d2*m)+b].push_back((1-d1)*m+a);//graph reversing

    g[(1-d2)*m+b].push_back((d1*m)+a);
    g1[(d1*m)+a].push_back((1-d2)*m+b);//graph reversing

  }

  for(int i=1;i<=2*m;i++)
    {
      if(vis[i])continue;
      dfs(i);
    }
    for(int i=1;i<=2*m;i++)vis[i]=0;
    int cnt=0;
    while(!s.empty())//SCC apply
    {
      int src=s.top();
     // dbg(src);
      s.pop();
      if(vis[src])continue;
      cnt++;
      reverse(src,cnt);
      //dbg(src,cnt);
    }
    vector<char>ans(m+1);
    for(int i=1;i<=m;i++)
    {
      if(col[i]==col[i+m])//same conncted component a hole task assigning possible na
      {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
      }
      //dbg(col[i],col[i+m]);
      if(col[i]<col[i+m])ans[i]='+';
      else ans[i]='-';
       
    }
    for(int i=1;i<=m;i++)cout<<ans[i];
      cout<<endl;


}
return 0;
}
