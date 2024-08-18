#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx];
struct info
{
    long long sum,prop;
};
struct info tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=a[b];return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e||j<b)return;
    if(b>=i&&e<=j)
    {
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
long long query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)
    {
        return tree[node].sum+carry*(e-b+1);
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;

}
int main()
{
   int t;cin>>t;
   for(int k=1;k<=t;k++)
   {
       for(int i=0;i<mx*3;i++)
       {
           tree[i].sum=0;
           tree[i].prop=0;
       }
       string s;cin>>s;
       int n=s.size();
       int q;
       init(1,1,n);
       cin>>q;
       printf("Case %d:\n",k);
       while(q--)
       {
           char c;cin>>c;
           if(c=='I')
           {
               int i,j;
               cin>>i>>j;
               update(1,1,n,i,j,1);

           }
           else
           {
               int i;cin>>i;
               int carry=0;
               int u=query(1,1,n,i,i,carry);//cout<<u<<endl;
               int d=s[i-1]-'0';
               if(u%2==0)
               {
                   cout<<d<<endl;
               }
               else cout<<1-d<<endl;
           }
       }
   }
}
