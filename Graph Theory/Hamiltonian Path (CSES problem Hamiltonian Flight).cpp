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

vector<vector<int>>g;
ll n,m;
ll dp[21][1<<20];
//path er start 1 and end n hote hobe


ll dfs(ll src,ll mask)
{
    if(__builtin_popcount(mask)==n)return 1;//mask er kotogula bit set
    else if(src==n)return 0;//sob node visit er agei jodi n k visit kore,tahole eta valid path na

    if(dp[src][mask]!=-1)return dp[src][mask];
    ll res=0;
    for(auto child:g[src])
    {
        if(mask & (1ll<<(child-1)))continue;
        res=(res+dfs(child,(mask | (1ll<<(child-1)))))%mod;
    }
    dp[src][mask]=res;
    return dp[src][mask];
}



int main()
{
  
//Q
{
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<(1ll<<20);j++)dp[i][j]=-1;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    ll ans=dfs(1,1);
    cout<<ans<<endl;
  
}
return 0;
}