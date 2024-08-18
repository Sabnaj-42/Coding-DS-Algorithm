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
ll base[2] = {281, 197};
ll mod[2] = {1000000289, 1000007117};
vector<vector<ll> > pw, vl;

void double_Hash(string s)
{
   ll n=s.size();
   pw.resize(n + 2, vector<ll> (2, 1) );
   vl.resize(n + 2, vector<ll> (2, 0) );
   for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
               vl[i + 1][j] = (vl[i][j] * base[j] % mod[j] + s[i] ) % mod[j];
                pw[i + 1][j] = (pw[i][j] * base[j]) % mod[j];
            }
        }
}

pair<ll,ll> hash_value(ll l,ll r)
{
    ll tmp1 = (vl[r+ 1][0] - (vl[l][0] * pw[r + 1 - l][0]) % mod[0] + mod[0]) % mod[0];
    ll tmp2 = (vl[r+ 1][1] - (vl[l][1] * pw[r + 1 - l][1]) % mod[1] + mod[1]) % mod[1];
    return {tmp1,tmp2};

}



int main()
{
  
  fast;
// Q
{
    string  s;
    cin>>s;
    ll n=s.size(),ans=0;
    double_Hash(s);
    //dbg("sabnaj");
   for(int len=1;len<=n;len++)
    {
     vector<pair<ll,ll>>v;
     for(int j=0;len+j-1<n;j++)
     {
      ll l=j,r=len+j-1;
      pair<ll,ll>p=hash_value(l,r);//l theke r porjonto substring er hash value.l,r inclusive
       v.push_back(p);
       //dbg(p);
     }
     sort(v.begin(),v.end());
      ans++;
      for(int j=1;j<v.size();j++)
      {
        if(v[j]!=v[j-1])ans++;
      }
    }
    
    cout<<ans<<endl;
}
return 0;
}

