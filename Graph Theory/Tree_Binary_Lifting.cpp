#include<bits/stdc++.h>
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>//sudhu less dile uniqe element rakhbe ,,less_equal dile duplicate value rakhbe
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
 
static ll mod=1e9+7;
 
long long big_mod(long long a,long long b,long long m)//[(a^b)%m] here b is very large number almost 1e9
{
    if(b==0)return (1%m);
    long long x=big_mod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)x=(x*a)%m;
    return x;
}
 
ll inf=1e9+7;
vector<ll>g[200005];
int  par[200005][21];
void Tree_binary_Lifting(int src,int p)
{
  for(auto child:g[src])
  {
    if(child==p)continue;
    par[child][0]=src;
    Tree_binary_Lifting(child,src);
  }
}


int main()
{
  fast;
  //Q
{
  int n,q;
   cin>>n>>q;
   for(int i=2;i<=n;i++)
   {
    int a;cin>>a;
    g[a].push_back(i);
    g[i].push_back(a);
   }
   for(int i=1;i<=n;i++)
   {
    for(int j=0;j<=20;j++)par[i][j]=-1;
   }
  Tree_binary_Lifting(1,-1);
  for(int i=1;i<=20;i++)
  {
    for(int j=1;j<=n;j++)
    {
      int d=par[j][i-1];
      if(d!=-1)
      {
        par[j][i]=par[d][i-1];
      }
      else
        par[j][i]=-1;
    }
  }

while(q--)
{
  int a,l;cin>>a>>l;
  int cnt=0;
  while(l>0)
  {
    int r=l%2;
    if(r==1)
    {
      a=par[a][cnt];
    }
    l/=2;
    cnt++;
    if(a==-1)break;
  }
  cout<<a<<endl;
}
      
}
return 0;
}
