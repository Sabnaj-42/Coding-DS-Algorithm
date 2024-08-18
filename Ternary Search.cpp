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

ll a[200005];
ll f(ll mid,ll b,ll x,ll n)
{
    ll j=mid;
    ll s=0;
    for(ll i=0;i<n;i++)
    {
      ll d=a[i];
      ll p=d/j;
      ll r=d%j;
      s+=((d*(d-1))/2)-(r*((p*(p+1))/2))-((j-r)*((p*(p-1))/2));
    }
    ll res=(s*b)-(mid-1)*x;
    return res;

}
    
int main()
{
  fast;
  Q

{
    ll n,b,x;cin>>n>>b>>x;
    for(int i=0;i<n;i++)cin>>a[i];
    ll mx=*max_element(a,a+n);
     ll l=1,r=mx+3;
     ll ans=0;
     while(r-l>=1)//Ternary Search
     {
        ll mid1=l+(r-l)/3;
        ll mid2=r-(r-l)/3;
        ll res1=f(mid1,b,x,n);
        ll res2=f(mid2,b,x,n);
        if(res1>res2)
        {
            r=mid2-1;
            ans=max(ans,res1);
        }
        else {
              l=mid1+1;
              ans=max(ans,res2);
          }
     }
     cout<<ans<<endl;
}
return 0;
}