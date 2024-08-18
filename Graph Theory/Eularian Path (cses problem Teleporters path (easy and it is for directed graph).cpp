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
vector<int>in,out,path;
void dfs(int src)
{
	while(!g[src].empty())
	{
		int child=g[src].back();
		g[src].pop_back();
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

	in.resize(n+1,0);out.resize(n+1,0); g.resize(n+1);

	for(int i=0;i<m;i++)
	{
		int a,b;cin>>a>>b;
		in[b]++;
		out[a]++;
		g[a].push_back(b);
	}
	bool ans=true;
    for(int i=2;i<n;i++){if(in[i]!=out[i]){ans=false;break;}}
    dfs(1);
    if(path.size()!=m+1){ans=false;}
    if(out[1]-in[1]!=1 || in[n]-out[n]!=1){ans=false;}
    
    if(!ans){cout<<"IMPOSSIBLE"<<endl;return 0;}
    for(int i=path.size()-1;i>=0;i--)
    {
    	cout<<path[i]<<" ";
    }
    cout<<endl;
  
}
//return 0;
}