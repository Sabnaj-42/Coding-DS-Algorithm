#include<bits/stdc++.h>
using namespace std;
#define mx 100002
long long a[mx+1];
struct edge
{
    long long x,y;
};
struct edge tree[3*mx];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].x=a[b];
        tree[node].y=0;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    long long s1=0,s2=0;
    if(tree[left].x>s1){s2=s1;s1=tree[left].x;}
    else if(tree[left].x>s2)s2=tree[left].x;
    if(tree[left].y>s1){s1=s2;s1=tree[left].y;}
    else if(tree[left].y>s2)s2=tree[left].y;
    if(tree[right].x>s1){s2=s1;s1=tree[right].x;}
    else if(tree[right].x>s2)s2=tree[right].x;
    if(tree[right].y>s1){s2=s1;s1=tree[right].y;}
    else if(tree[right].y>s2)s2=tree[right].y;
    tree[node].x=s1;
    tree[node].y=s2;

}
void update(int node,int b,int e,int i,int v)
{
    if(i>e||i<b)return;
    if(b>=i&&e<=i)
    {

        tree[node].x=v;
        tree[node].y=1;
        return ;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,v);
    update(right,mid+1,e,i,v);
    long long s1=0,s2=0;
    if(tree[left].x>s1){s2=s1;s1=tree[left].x;}
    else if(tree[left].x>s2)s2=tree[left].x;
    if(tree[left].y>s1){s1=s2;s1=tree[left].y;}
    else if(tree[left].y>s2)s2=tree[left].y;
    if(tree[right].x>s1){s2=s1;s1=tree[right].x;}
    else if(tree[right].x>s2)s2=tree[right].x;
    if(tree[right].y>s1){s2=s1;s1=tree[right].y;}
    else if(tree[right].y>s2)s2=tree[right].y;
    tree[node].x=s1;
    tree[node].y=s2;

}

struct edge query(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)
    {
        struct edge m;
        m.x=0;m.y=0;
        return m;
    }
    if(b>=i&&e<=j)

    {

        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    struct edge p1=query(left,b,mid,i,j);
    struct edge p2=query(right,mid+1,e,i,j);
    long long s1=0,s2=0;
    struct edge r;
    if(p1.x>s1){s2=s1;s1=p1.x;}
    else if(p1.x>s2)s2=p1.x;
    if(p1.y>s1){s1=s2;s1=p1.y;}
    else if(p1.y>s2)s2=p1.y;
    if(p2.x>s1){s2=s1;s1=p2.x;}
    else if(p2.x>s2)s2=p2.x;
    if(p2.y>s1){s2=s1;s1=p2.y;}
    else if(p2.y>s2)s2=p2.y;
    r.x=s1;
    r.y=s2;

    return r;


}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    init(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='U')
        {
            long long i,v;
            cin>>i>>v;
            update(1,1,n,i,v);
        }
        else
        {
            long long i,j;
            struct edge ans;
            cin>>i>>j;
            ans=query(1,1,n,i,j);
            cout<<ans.x+ans.y<<endl;
        }
    }
}

