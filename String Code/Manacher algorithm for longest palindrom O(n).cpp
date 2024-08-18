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
 
ll inf=-1e6;

vector<int> manacher(string s)
{
  string t="";
  for(auto x:s)//even and odd both length substring handle
  {
    t+='#';
    t+=x;
  }
  t+='#';
 // cout<<t<<endl;
  int n=t.size();
  vector<int>p(n+1,1);//i th index er both side a koyta palindrom matching ache
  int l=1,r=1;//l and r both are exclusive
  for(int i=1;i<n;i++)
  {
    p[i]=max(1,min(r-i,p[l+r-i]));
    while(i+p[i]<n && i-p[i]>=0 && t[i+p[i]]==t[i-p[i]] )
       p[i]++;
     if(i+p[i]>r)
     {
      r=i+p[i];
      l=i-p[i];
     }
  }
  return p;
}


int main()
{
  
  fast;
 Q
{
  string s;cin>>s;
  vector<int>p=manacher(s);
  dbg(p);
  
}
return 0;
}