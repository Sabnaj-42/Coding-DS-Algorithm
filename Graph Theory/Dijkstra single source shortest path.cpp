#include<bits/stdc++.h>
using namespace std;
#define ll long long

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


const ll inf=1e18;
vector<ll>dist(100005,inf);
vector<pair<ll,ll>>graph[100005];
void dijkstra(ll src)
{
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater< pair<ll,ll>>>pq;
   pq.push({0,src});
   dist[src]=0;
   while(!pq.empty())
   {
       ll curdis=pq.top().first;
       ll curnod=pq.top().second;
       pq.pop();
       if(dist[curnod]<curdis)continue;
           for(auto child:graph[curnod])
           {
               if(dist[child.first]>curdis+child.second)
               {
                   dist[child.first]=curdis+child.second;
                   pq.push({dist[child.first],child.first});
               }
           }
   }
}
int main()
{
  ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>>g[n+1];

    for(int i=1;i<=m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    dijkstra(1);
     priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater< pair<ll,ll>>>q;
     for(ll i=1;i<=n;i++)
     {
      q.push({dist[i],i});
     }
     while(!q.empty())
     {
      ll d=q.top().second;
      ll w=q.top().first;
      q.pop();
      if(dist[d]<w)continue;
      for(auto child:g[d])
      {
         ll l=child.second+dist[d];
        if(l<dist[child.first])
        {
          dist[child.first]=l;
          q.push({l,child.first});
        }
      }
     }
     for(int i=2;i<=n;i++)
      {
        if(dist[i]==inf)dist[i]=-1;
        cout<<dist[i]<<" ";
      }
      cout<<"\n";

}
