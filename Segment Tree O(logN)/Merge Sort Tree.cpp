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
const ll inf=1e17;
const ll mx=100000;

ll a[100005];
vector<ll>treee[mx*4];

void build_merge_sort_tree(ll node,ll b,ll e)//treee[node] a jei vector tate er sob gula subtree (b tekhe e porjonto element)(ancestor) er value and a er nijer value sorted thakbe
{
 if(b==e){treee[node].push_back(a[b]);return;}
 int left=node*2;
 int right=left+1;
 int mid=(b+e)/2;
 build_merge_sort_tree(left,b,mid);
 build_merge_sort_tree(right,mid+1,e);
 int i=0,j=0;
 while(i<treee[left].size() && j<treee[right].size())
 {
  if(treee[left][i]<=treee[right][j]){treee[node].push_back(treee[left][i]);i++;}
  else {treee[node].push_back(treee[right][j]);j++;}
 }
 while(i<treee[left].size())
 {
  treee[node].push_back(treee[left][i]);i++;
 }
 while(j<treee[right].size())
 {
  treee[node].push_back(treee[right][j]);j++;
 }
}

ll query(ll node,ll b,ll e,ll l,ll r,ll mn,ll mx)//renge l to r index a (mn thke mx er moddhe koto gula value ache) l,r,mn,mx inclusive
{
  if(b>r || e<r)return 0;
  if(b>=l && e<=r)
  {
    ll fastt=lower_bound(treee[node].begin(),treee[node].end(),mn)-treee[node].begin();
    ll lastt=upper_bound(treee[node].begin(),treee[node].end(),mx)-treee[node].begin()-1;
    ll res=max(0ll,lastt-fastt+1);
    return res; 
  }
  int mid=(b+e)/2;
  int res1=query(node*2,b,mid,l,r,mn,mx);
  int res2=query(node*2+1,mid+1,e,l,r,mn,mx);
  return res1+res2;
}



void solve()
{
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
  build_merge_sort_tree(1,1,n);
  while(q--)
  {
    ll l,r,mn,mx;
    cin>>l>>r>>mn>>mx;
    ll ans=query(1,1,n,l,r,mn,mx);
    cout<<ans<<endl;
  }

}

int main()
{
  fast;
  //Q
  {
    solve();
  }
}