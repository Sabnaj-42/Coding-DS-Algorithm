#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,w;
};
struct node ar [100];
bool cmp(node a,node b)
{
    if(a.w<b.w)return true;
    else return false;
}
int par[100];
int findd(int a)
{
    if(par[a]==a)return a;
    else return par[a]=findd(par[a]);
}
void unionn(int u,int v)
{
    par[u]=v;
}
int ans=INT_MAX,cost1=0;
void mst(int e,int m,int edge)
{
    int cost=0,cnt=1;
    for(int i=0;i<m;i++)
    {
       if(i==e)continue;
       int u=findd(ar[i].a);
       int v=findd(ar[i].b);
       if(u!=v)
       {
           cost=cost+ar[i].w;
           unionn(u,v);
           cnt++;
       }
    }
    if(cnt>=edge)
    {
        if(cost>cost1)
            {ans=min(ans,cost);}
    }
}
void mmst(int m)
{
    for(int i=0;i<m;i++)
    {
       int u=findd(ar[i].a);
       int v=findd(ar[i].b);
       if(u!=v)
       {
           cost1=cost1+ar[i].w;
           unionn(u,v);
       }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {

        cin>>ar[i].a>>ar[i].b>>ar[i].w;

    }
    sort(ar,ar+m,cmp);
    for(int i=1;i<=n;i++)par[i]=i;
    mmst(m);
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)par[j]=j;
        mst(i,m,n);
    }
    cout<<ans<<endl;

}
