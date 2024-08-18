#include<bits/stdc++.h>
using namespace std;
#define ll   long long
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
 
ll parse[100005][21];
ll a[100005];
void sparsegen(ll n)//n is array size. O(nlog(n))time lagbe sparse table generate korte
{
  for(ll i=1;i<=n;i++)parse[i][0]=a[i];
  for(ll i=1;(1<<i)<=n;i++)
  {
    for(ll j=1;j+(1<<i)-1<=n;j++)
    {
      parse[j][i]=parse[j][i-1]&parse[j+(1<<(i-1))][i-1];

    }
   
  }
}

// range query te use hoy, range er minimum ,maximu, and value ber korte sparse tree use hoy. query complexity o(1)

ll qpar(ll low,ll high)// l to r range er element er and (&) value ber korbe O(1) time a
{
  ll d=(high-low+1);
  ll k=log2l(d);
  return parse[low][k]&parse[high-(1<<k)+1][k];
}

int main()
{
  fast;
  Q
{
  ll n;
  cin>>n;
  a[0]=0;
  for(int i=1;i<=n;i++)cin>>a[i];
  sparsegen(n);
  ll q;cin>>q;
  while(q--)
  {
    ll l,r;cin>>l>>r;
    ll d=qpar(l,r);
    cout<<d<<endl;
  }
}
 
}