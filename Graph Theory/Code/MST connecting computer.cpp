

#include<bits/stdc++.h>
using namespace std;

int parent[1000005];

struct edge
{
    int a,b,w;
};
struct edge ar[5000005];
bool comp (edge a,edge b)
{
    if(a.w<b.w)return true;
    else return false;
}

int findd(int a)
{
    if(parent[a]==a)return a;
    else
    {
        return parent[a]=findd(parent[a]);
    }
}
void unionn(int a,int b)
{
    parent[a]=b;
}

int main()
{
    int n,m;

        cin>>n>>m;
        long long sum=0;
        for(int i=1;i<=n;i++)parent[i]=i;
        for(int i=0;i<m;i++)
        {
           cin>>ar[i].a>>ar[i].b>>ar[i].w;
        }
        sort(ar,ar+m,comp);
        for(int i=0; i<m; i++)
        {
            int u=findd(ar[i].a);
            int v=findd(ar[i].b);
            if(u!=v)
            {
                sum+=ar[i].w;
                unionn(u,v);
            }
        }
         cout<<sum<<endl;

}
