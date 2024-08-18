#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int FT[mx*2];//kono ekta node er staring time and ending time(index is time,value hocche oi time a discover howa node
int S[mx],T[mx];//index hocche node value hocche oi node visit kora time
vector<int>g[mx];
int timer;
void dfs(int src,int par)//DFS function for Euler tour
{
    S[src]=timer;
    FT[timer]=src;
    timer++;
    for(int child:g[src])
    {
        if(child!=par)
            dfs(child,src);
    }
    T[src]=timer;
    FT[timer]=src;
    timer++;
}
int main()
{
   int n;cin>>n;
   for(int i=1;i<n;i++)
   {
       int a,b;cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
   }
   timer=1;
   dfs(1,-1);
   int q;cin>>q;
   while(q--)
   {
       int c,x,y;cin>>c>>x>>y;
       int sx=S[x];
       int sy=S[y];
       if(c==0)
       {
          if(sx>sy)cout<<"NO"<<"\n";
          else
          {
              int tx=T[x];
              int ty=T[y];
              if(sy>sx&&ty<tx)cout<<"YES"<<"\n";
              else cout<<"NO"<<"\n";
          }
       }
       else
       {
          if(sy>sx) cout<<"NO"<<"\n";
          else
          {
              int tx=T[x];
              int ty=T[y];
              if(sx>sy&&tx<ty)cout<<"YES"<<"\n";
              else cout<<"NO"<<"\n";
          }
       }

   }
}
