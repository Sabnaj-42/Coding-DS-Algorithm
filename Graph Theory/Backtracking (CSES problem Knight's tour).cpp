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

int xmove[]={1,1,2,2,-1,-1,-2,-2};
int ymove[]={2,-2,1,-1,2,-2,1,-1};

int ans[8][8];

int dfs(int x,int y,int move)
{
  if(move==64)return 1;

  /* Try all next moves from
    the current coordinate x, y */
  for(int i=0;i<8;i++)
  {
    int  n_x=x+xmove[i];
    int n_y=y+ymove[i];
    if((n_x>=0 && n_x<8) && (n_y>=0 && n_y<8) && (ans[n_x][n_y]==-1))
    {
      ans[n_x][n_y]=move;
      int res= dfs(n_x,n_y,move+1);
      if(res==1)return 1;
      else ans[n_x][n_y]=-1; // backtracking
    }
  }
  return 0;
}




int main()
{
  
  fast;
//Q
{
  int x,y;
  cin>>x>>y;//starting co-ordinate

  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)ans[i][j]=-1;
  }

  ans[y-1][x-1]=0;
  bool res=dfs(y-1,x-1,1);
  if(!res){cout<<"IMPOSSIBLE"<<endl;return 0;}

  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)cout<<ans[i][j]+1<<" ";
    cout<<endl;
  }

  
}
return 0;
}