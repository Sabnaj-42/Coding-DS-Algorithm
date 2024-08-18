#include<bits/stdc++.h>
using namespace std;
#define mx 1000
int a[mx];
int tree[mx*3];
void init(int node,int b,int e)//creation segment tree// 1 theke node r b start korbo
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)//finding sum in range index i to j(i and j inclusive)
{
    if(i>e||j<b)return 0;//out of range
    if(b>=i&&e<=j)return tree[node];//full segment in range
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;//sum of left child and right child
}
void update(int node,int b,int e,int i,int newvalue)//update in segment tree
{
    if(i>e||i<b)return;//out of range
    if(b>=i&&e<=i)//in segment (deiser index node)
    {
        tree[node]=newvalue;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];


}
int main()
{
   int n;cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   init(1,1,n);
   int i,j;cin>>i>>j;
   cout<<query(1,1,n,i,j);

}
