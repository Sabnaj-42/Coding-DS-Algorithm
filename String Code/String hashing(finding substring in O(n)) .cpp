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

long long big_mod(long long a,long long b,long long m)//[(a^b)%m] here b is very large number almost 1e9
{
    if(b==0)return (1%m);
    long long x=big_mod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)x=(x*a)%m;
    return x;
}

ll p=10039;//prime number for multiplying by p^i
 
ll inf=-1e6;
vector<ll>inv(200005);//inverse module of p^i to calculating of substring

vector<ll>hashing(string s)
{
  ll n=s.size();
  vector<ll>pre(n,0);
  pre[0]=s[0]-'a'+1;
  inv[0]=1;
  ll pow_p=1;
  for(int i=1;i<n;i++)
  {
    pow_p*=p;
    pow_p%=mod;
    inv[i]=big_mod(pow_p,mod-2,mod);
    pre[i]=(pre[i-1]+(s[i]-'a'+1)*pow_p)%mod;
  }
  return pre;
}





int main()
{
  
  fast;
 Q
{
  string s;cin>>s;
  vector<ll>pre=hashing(s);
  int q;cin>>q;
  while(q--)
  {
    ll l,r;
    cin>>l>>r;
    l--;r--;

    ll ans=pre[r];
    //dbg(ans);
    if(l>0)ans-=pre[l-1];
    //dbg(ans);
    ans*=inv[l];//divding by p^l using modular inverse,
    ans%=mod;
    cout<<ans<<endl;

  }
  
}
return 0;
}