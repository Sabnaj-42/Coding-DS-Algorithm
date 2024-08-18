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
 
static ll mod=1e9+7;
ll inf=1e12;
 
long long big_mod(long long a,long long b,long long m)//[(a^b)%m] here b is very large number almost 1e9
{
    if(b==0)return (1%m);
    long long x=big_mod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)x=(x*a)%m;
    return x;
}

void solve() {
  // input data
  ll n,q;cin>>n>>q;
  ll a[n+1];
  ll len = (ll) sqrt (n + .0) + 1; // size of the block and the number of blocks
  vector<ll> b_mx(len+1,0);
  // preprocessing
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
     b_mx[i/len]=max(b_mx[i/len],a[i]);
    }


while(q--)
{
  ll x,y;//x thke r index er moddhe maximum element ber korbe
  cin>>x>>y;//each query te time lagbe sqrt(n);

   x--;y--;//1 base k 0 base a convert
   
   ll l=x/len,r=y/len;//first and last block;
   if(l==r)
   {
    ll res_mx=0;
     for(ll i=x;i<=y;i++)
     {
      res_mx=max(res_mx,a[i]);
     }
     cout<<res_mx<<endl;
     continue;
   }
   ll res_mx=0;
   for (ll i=x, end=(l+1)*len-1; i<=min(n-1,end); i++)//element in starting block
        {
          res_mx=max(res_mx,a[i]);
        }
    for (ll i=l+1; i<r; i++)//elemet of the block except first and last block in range
    {
        res_mx=max(res_mx,b_mx[i]);
    }
    for (ll i=r*len; i<=y; i++)//element of the last block in the range
        {
          res_mx=max(res_mx,a[i]);
        }
   cout<<res_mx<<endl;
}


}



    
int main()
{
  fast;
 //Q

{
  solve();
  
}
return 0;
}